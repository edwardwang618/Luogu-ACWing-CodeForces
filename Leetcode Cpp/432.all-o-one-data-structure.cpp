/*
 * @lc app=leetcode id=432 lang=cpp
 *
 * [432] All O`one Data Structure
 */

// @lc code=start
class AllOne {
 public:
  struct Node {
    Node *prev, *next;
    unordered_set<string> keys;
    int cnt;

    Node(const string& key, int cnt) {
      keys.insert(key);
      this->cnt = cnt;
    }
  };

  struct LinkedList {
    Node *head, *tail;
    int sz;

    LinkedList() {
      head = new Node("", 0);
      tail = new Node("", 0);
      head->next = tail;
      tail->prev = head;
    }

    void add_first(Node* node) { add_after(head, node); }

    void add_after(Node* cur, Node* node) {
      node->prev = cur;
      node->next = cur->next;
      cur->next = node;
      node->next->prev = node;
      sz++;
    }

    void remove(Node* node) {
      node->prev->next = node->next;
      node->next->prev = node->prev;
      sz--;
    }

    bool empty() { return sz == 0; }
  };

  LinkedList list;
  unordered_map<string, Node*> mp;

  AllOne() {}

  void inc(string key) {
    if (!mp.count(key)) {
      if (list.empty() || list.head->next->cnt != 1) {
        auto node = new Node(key, 1);
        list.add_first(node);
        mp[key] = node;
      } else {
        list.head->next->keys.insert(key);
        mp[key] = list.head->next;
      }
    } else {
      auto node = mp[key];
      node->keys.erase(key);
      if (node->next == list.tail || node->next->cnt != node->cnt + 1)
        list.add_after(node, new Node(key, node->cnt + 1));
      mp[key] = node->next;
      node->next->keys.insert(key);
      if (node->keys.empty()) list.remove(node);
    }
  }

  void dec(string key) {
    if (!mp.count(key)) return;
    auto node = mp[key];
    node->keys.erase(key);
    if (node->cnt == 1)
      mp.erase(key);
    else {
      if (node->prev == list.head || node->prev->cnt != node->cnt - 1)
        list.add_after(node->prev, new Node(key, node->cnt - 1));
      node->prev->keys.insert(key);
      mp[key] = node->prev;
    }
    if (node->keys.empty()) list.remove(node);
  }

  string getMaxKey() {
    if (list.empty()) return "";
    return *list.tail->prev->keys.begin();
  }

  string getMinKey() {
    if (list.empty()) return "";
    return *list.head->next->keys.begin();
  }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
// @lc code=end
