/*
 * @lc app=leetcode id=2502 lang=cpp
 *
 * [2502] Design Memory Allocator
 */

// @lc code=start
class Allocator {
public:
  struct Node {
    int l, r;
    int mID;
    Node *prev, *next;
    Node(int l, int r, int mID)
        : l(l), r(r), mID(mID), prev(nullptr), next(nullptr) {}
  };
  struct NodeAllocator {
    Node *freehead;
    vector<void *> pools;
    int chunksize = 16;
    NodeAllocator() {
      pools.push_back(::operator new(chunksize * sizeof(Node)));
      freehead = static_cast<Node *>(pools.back());
      for (int i = 0; i < chunksize; i++)
        freehead[i].next = i + 1 < chunksize ? &freehead[i + 1] : nullptr;
    }

    Node *allocate(int l, int r, int mID) {
      if (!freehead) {
        pools.push_back(::operator new(chunksize * sizeof(Node)));
        freehead = static_cast<Node *>(pools.back());
        for (int i = 0; i < chunksize; i++)
          freehead[i].next = i + 1 < chunksize ? &freehead[i + 1] : nullptr;
        chunksize *= 2;
      }
      Node *next = freehead->next;
      Node *node = new (freehead) Node(l, r, mID);
      freehead = next;
      return node;
    }

    void deallocate(Node *p) {
      p->next = freehead;
      freehead = p;
    }

    ~NodeAllocator() {
      for (auto *p : pools)
        ::operator delete(p);
    }
  } node_allocator;

  Node *head, *tail;
  Allocator(int n) {
    head = node_allocator.allocate(-1, -1, -1);
    tail = node_allocator.allocate(-1, -1, -1);
    Node *node = node_allocator.allocate(0, n - 1, 0);
    head->next = node;
    node->prev = head;
    tail->prev = node;
    node->next = tail;
  }

  int allocate(int size, int mID) {
    for (Node *p = head->next; p != tail; p = p->next) {
      int l = p->l, r = p->r;
      if (p->mID)
        continue;
      if (r - l + 1 >= size) {
        p->mID = mID;
        if (r - l + 1 > size) {
          Node *ne = node_allocator.allocate(l + size, r, 0);
          ne->next = p->next;
          ne->prev = p;
          p->next = ne;
          ne->next->prev = ne;
          p->r = l + size - 1;
        }
        return l;
      }
    }
    return -1;
  }

  // p->mID == 0
  void mergePrevAndNext(Node *p) {
    if (!p->prev->mID) {
      Node *pr = p->prev;
      p->prev = pr->prev;
      pr->prev->next = p;
      p->l = pr->l;
      node_allocator.deallocate(pr);
    }
    if (!p->next->mID) {
      Node *ne = p->next;
      p->next = ne->next;
      ne->next->prev = p;
      p->r = ne->r;
      node_allocator.deallocate(ne);
    }
  }

  int freeMemory(int mID) {
    int res = 0;
    for (Node *p = head->next; p != tail; p = p->next) {
      int l = p->l, r = p->r;
      if (p->mID != mID)
        continue;

      res += r - l + 1;

      p->mID = 0;
      mergePrevAndNext(p);
    }
    return res;
  }
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->freeMemory(mID);
 */
// @lc code=end
