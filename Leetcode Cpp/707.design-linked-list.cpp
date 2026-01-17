/*
 * @lc app=leetcode id=707 lang=cpp
 *
 * [707] Design Linked List
 */

// @lc code=start
class MyLinkedList {
public:
  struct Node {
    Node *prev, *next;
    int val;
    Node(int x) : prev(nullptr), next(nullptr), val(x) {}
    Node(int x, Node *prev, Node *next) : prev(prev), next(next), val(x) {}
  };

  struct Allocator {
    int chunksize = 16;
    Node *freehead;
    vector<void *> pools;
    Allocator() {
      pools.emplace_back(::operator new(chunksize * sizeof(Node)));
      freehead = static_cast<Node *>(pools[0]);
      for (int i = 0; i + 1 < chunksize; i++)
        freehead[i].next = &freehead[i + 1];
      freehead[chunksize - 1].next = nullptr;
    }

    ~Allocator() {
      static_assert(is_trivially_destructible<Node>::value,
                    "Node is not trivially destructible.");
      for (void *pool : pools)
        ::operator delete(pool);
    }

    void grow() {
      void *pool = ::operator new(chunksize * sizeof(Node));
      Node *node = static_cast<Node *>(pool);
      for (int i = 0; i < chunksize; i++)
        node[i].next = i + 1 < chunksize ? &node[i + 1] : freehead;
      freehead = node;
      chunksize *= 2;
    }

    Node *allocate(int x, Node *prev = nullptr, Node *next = nullptr) {
      if (!freehead)
        grow();
      Node *cur = freehead;
      freehead = freehead->next;
      new (cur) Node(x, prev, next);
      return cur;
    }

    void deallocate(Node *p) {
      p->next = freehead;
      freehead = p;
    }

  } allocator;

  Node *head, *tail;
  int sz;

  MyLinkedList()
      : allocator(), head(allocator.allocate(0)), tail(allocator.allocate(0)),
        sz(0) {
    head->next = tail;
    tail->prev = head;
  }

  Node *operator[](int idx) {
    if (idx < 0 || idx >= sz)
      return nullptr;
    Node *res;
    if (idx < sz / 2) {
      res = head;
      for (int i = 0; i <= idx; i++)
        res = res->next;
    } else {
      res = tail;
      for (int i = 0; i < sz - idx; i++)
        res = res->prev;
    }
    return res;
  }

  int get(int idx) {
    if (auto node = (*this)[idx]; node)
      return node->val;
    return -1;
  }

  void addAtHead(int val) {
    auto node = allocator.allocate(val, head, head->next);
    head->next = node;
    node->next->prev = node;
    sz++;
  }

  void addAtTail(int val) {
    auto node = allocator.allocate(val, tail->prev, tail);
    tail->prev = node;
    node->prev->next = node;
    sz++;
  }

  void addAtIndex(int idx, int val) {
    if (idx == sz)
      addAtTail(val);
    else if (auto node = (*this)[idx]; node) {
      node->prev = allocator.allocate(val, node->prev, node);
      node->prev->prev->next = node->prev;
      sz++;
    }
  }

  void deleteAtIndex(int idx) {
    if (auto node = (*this)[idx]; node) {
      node->prev->next = node->next;
      node->next->prev = node->prev;
      allocator.deallocate(node);
      sz--;
    }
  }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
// @lc code=end
