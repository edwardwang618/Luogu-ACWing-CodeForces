/*
 * @lc app=leetcode id=1206 lang=cpp
 *
 * [1206] Design Skiplist
 */

// @lc code=start
class Skiplist {
public:
  static constexpr int MAX_LEVEL = 8;
  struct Node {
    int val;
    Node *next[MAX_LEVEL];
    Node(int val) : val(val) { memset(next, 0, sizeof(next)); }
  };

  struct Allocator {
    Node *freehead = nullptr;
    int chunksize = 16;
    vector<void *> pools;
    ~Allocator() {
      static_assert(is_trivially_destructible<Node>::value,
                    "Node is not trivially destructible.");
      for (auto *pool : pools)
        ::operator delete(pool);
    }

    void expand() {
      pools.emplace_back(::operator new(chunksize * sizeof(Node)));
      Node *node = static_cast<Node *>(pools.back());
      for (int i = 0; i < chunksize; i++)
        node[i].next[0] = i + 1 < chunksize ? &node[i + 1] : nullptr;
      freehead = node;
      chunksize *= 2;
    }

    Node *allocate(int x) {
      if (!freehead)
        expand();
      Node *next = freehead->next[0];
      Node *node = new (freehead) Node(x);
      freehead = next;
      return node;
    }

    void deallocate(Node *p) {
      p->next[0] = freehead;
      freehead = p;
    }
  } allocator;

  Node *head;
  Node *pre[MAX_LEVEL];

  Skiplist() { head = allocator.allocate(-1); }

  void find(int x) {
    auto p = head;
    for (int i = MAX_LEVEL - 1; i >= 0; i--) {
      while (p->next[i] && p->next[i]->val < x)
        p = p->next[i];
      pre[i] = p;
    }
  }

  bool search(int x) {
    find(x);
    auto p = pre[0]->next[0];
    return p && p->val == x;
  }

  void add(int x) {
    find(x);
    auto p = allocator.allocate(x);
    for (int i = 0; i < MAX_LEVEL; i++) {
      p->next[i] = pre[i]->next[i];
      pre[i]->next[i] = p;
      if (rand() & 1)
        break;
    }
  }

  bool erase(int x) {
    find(x);
    auto p = pre[0]->next[0];
    if (!p || p->val != x)
      return false;
    for (int i = 0; i < MAX_LEVEL && pre[i]->next[i] == p; i++)
      pre[i]->next[i] = p->next[i];
    allocator.deallocate(p);
    return true;
  }
};

/**
 * Your Skiplist object will be instantiated and called as such:
 * Skiplist* obj = new Skiplist();
 * bool param_1 = obj->search(target);
 * obj->add(num);
 * bool param_3 = obj->erase(num);
 */
// @lc code=end
