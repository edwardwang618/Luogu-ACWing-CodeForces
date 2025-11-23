/*
 * @lc app=leetcode id=146 lang=cpp
 *
 * [146] LRU Cache
 */

// @lc code=start
class LRUCache {
 public:
  struct ListNode {
    ListNode *prev, *next;
    int key, val;
    ListNode(int key, int val) {
      this->key = key;
      this->val = val;
      prev = next = nullptr;
    }
  };
  using node_p = ListNode *;
  node_p head, tail;
  node_p nn(int key, int val) { return new ListNode(key, val); }
  unordered_map<int, node_p> mp;
  int sz, cap;

  LRUCache(int capacity) {
    cap = capacity;
    sz = 0;
    head = nn(0, 0), tail = nn(0, 0);
    head->next = tail, tail->prev = head;
  }

  node_p delink(node_p node) {
    if (node->next) node->next->prev = node->prev;
    if (node->prev) node->prev->next = node->next;
    return node;
  }

  void move_to_head(node_p node) {
    delink(node);
    node->next = head->next, node->prev = head;
    head->next = node, node->next->prev = node;
  }

  int get(int key) {
    if (!mp.count(key)) return -1;
    auto node = mp[key];
    move_to_head(node);
    return node->val;
  }

  void put(int key, int value) {
    if (mp.count(key)) {
      auto node = mp[key];
      node->val = value;
      move_to_head(node);
    } else {
      sz++;
      move_to_head(nn(key, value));
      mp[key] = head->next;
      if (sz > cap) {
        mp.erase(delink(tail->prev)->key);
        sz--;
      }
    }
  }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end
