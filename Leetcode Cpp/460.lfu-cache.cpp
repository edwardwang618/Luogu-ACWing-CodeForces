/*
 * @lc app=leetcode id=460 lang=cpp
 *
 * [460] LFU Cache
 */

// @lc code=start
class LFUCache {
 private:
  struct Node {
    int key, val, freq;
    Node *prev, *next;
    Node(int key, int val)
        : key(key), val(val), prev(nullptr), next(nullptr), freq(1) {}
  };
  struct LinkedList {
    Node *head, *tail;
    int sz;
    LinkedList() : sz(0) {
      head = new Node(0, 0);
      tail = new Node(0, 0);
      head->next = tail;
      tail->prev = head;
    }

    void addFirst(Node *node) {
      node->prev = head;
      node->next = head->next;
      head->next = node;
      node->next->prev = node;
      sz++;
    }

    void remove(Node *node) {
      if (!sz) return;
      node->prev->next = node->next;
      node->next->prev = node->prev;
      sz--;
    }

    Node *removeLast() {
      if (!sz) return nullptr;
      auto *res = tail->prev;
      remove(res);
      return res;
    }
  };

  unordered_map<int, Node *> nodemp;
  unordered_map<int, LinkedList *> freq;
  int cap, minFreq;

  void update(Node *node) {
    auto *list = freq[node->freq];
    list->remove(node);
    if (node->freq == minFreq && !list->sz) minFreq++;
    node->freq++;
    if (!freq.count(node->freq)) freq[node->freq] = new LinkedList();
    freq[node->freq]->addFirst(node);
  }

  void removeOldest() {
    auto *list = freq[minFreq];
    auto *node = list->removeLast();
    nodemp.erase(node->key);
  }

 public:
  LFUCache(int capacity) {
    freq[1] = new LinkedList();
    cap = capacity;
    minFreq = 0;
  }

  int get(int key) {
    if (!nodemp.count(key)) return -1;
    auto *node = nodemp[key];
    update(node);
    return node->val;
  }

  void put(int key, int value) {
    if (!cap) return;
    if (nodemp.count(key)) {
      auto *node = nodemp[key];
      node->val = value;
      update(node);
      return;
    }

    if (nodemp.size() == cap) removeOldest();
    auto *node = new Node(key, value);
    nodemp[key] = node;
    freq[1]->addFirst(node);
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
