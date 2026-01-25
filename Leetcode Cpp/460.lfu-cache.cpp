/*
 * @lc app=leetcode id=460 lang=cpp
 *
 * [460] LFU Cache
 */

// @lc code=start
class LFUCache {
  struct Node {
    int key, val, freq;
    Node *prev, *next;
    Node(int key, int val)
        : key(key), val(val), prev(nullptr), next(nullptr), freq(1) {}
  };

  struct Allocator {
    Node *freehead;
    int chunksize = 16;
    vector<void *> pools;
    Allocator() {
      pools.emplace_back(::operator new(chunksize * sizeof(Node)));
      freehead = static_cast<Node *>(pools[0]);
      for (int i = 0; i < chunksize; i++)
        freehead[i].next = i + 1 < chunksize ? &freehead[i + 1] : nullptr;
    }

    ~Allocator() {
      static_assert(is_trivially_destructible<Node>::value,
                    "Node is not trivially destructible.");
      for (void *pool : pools)
        ::operator delete(pool);
    }

    Node *allocate(int key, int val) {
      if (!freehead) {
        pools.emplace_back(::operator new(chunksize * sizeof(Node)));
        Node *node = static_cast<Node *>(pools.back());
        for (int i = 0; i < chunksize; i++)
          node[i].next = i + 1 < chunksize ? &node[i + 1] : nullptr;
        freehead = node;
        chunksize *= 2;
      }
      Node *next = freehead->next;
      Node *node = new (freehead) Node(key, val);
      freehead = next;
      return node;
    }

    void deallocate(Node *p) {
      p->next = freehead;
      freehead = p;
    }
  } allocator;
  struct LinkedList {
    Node *head, *tail;
    void init(Node *head, Node *tail) {
      this->head = head;
      this->tail = tail;
      this->head->next = this->tail;
      this->tail->prev = this->head;
    }

    void addFirst(Node *node) {
      node->prev = head;
      node->next = head->next;
      head->next = node;
      node->next->prev = node;
    }

    void remove(Node *node) {
      node->prev->next = node->next;
      node->next->prev = node->prev;
    }

    Node *removeLast() {
      auto *res = tail->prev;
      remove(res);
      return res;
    }

    bool empty() { return head->next == tail; }
  };

  unordered_map<int, Node *> nodemp;
  unordered_map<int, LinkedList> freq;
  int cap, minFreq;

  void update(Node *node) {
    auto &list = freq[node->freq];
    list.remove(node);
    if (node->freq == minFreq && list.empty()) minFreq++;
    node->freq++;
    auto [it, ins] = freq.try_emplace(node->freq);
    if (ins)
      it->second.init(allocator.allocate(0, 0), allocator.allocate(0, 0));
    it->second.addFirst(node);
  }

  void removeOldest() {
    auto &list = freq[minFreq];
    auto *node = list.removeLast();
    nodemp.erase(node->key);
    allocator.deallocate(node);
  }

public:
  LFUCache(int capacity) : cap(capacity), minFreq(0) {
    freq[1].init(allocator.allocate(0, 0), allocator.allocate(0, 0));
  }

  int get(int key) {
    Node *node;
    if (auto it = nodemp.find(key); it == nodemp.end()) return -1;
    else node = it->second;
    update(node);
    return node->val;
  }

  void put(int key, int value) {
    if (!cap) return;
    auto &node = nodemp[key];
    if (node) {
      node->val = value;
      update(node);
      return;
    }

    if (nodemp.size() > cap) removeOldest();
    node = allocator.allocate(key, value);
    freq[1].addFirst(node);
    minFreq = 1;
  }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end
