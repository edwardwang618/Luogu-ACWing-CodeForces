/*
 * @lc app=leetcode id=1206 lang=cpp
 *
 * [1206] Design Skiplist
 */

// @lc code=start
class Skiplist {
 public:
#define level 8
  struct Node {
    int val;
    vector<Node*> next;
    Node(int val) : val(val) {
      next.resize(level, nullptr);
    }
  } *head;

  Skiplist() {
    head = new Node(-1);
  }

  ~Skiplist() {
    delete head;
  }

  void find(int x, vector<Node*> &pre) {
    auto p = head;
    for (int i = level - 1; i >= 0; i--) {
      while (p->next[i] && p->next[i]->val < x) p = p->next[i];
      pre[i] = p;
    }
  }

  bool search(int x) {
    vector<Node*> pre(level);
    find(x, pre);
    auto p = pre[0]->next[0];
    return p && p->val == x;
  }

  void add(int x) {
    vector<Node*> pre(level);
    find(x, pre);
    auto p = new Node(x);
    for (int i = 0; i < level; i++) {
      p->next[i] = pre[i]->next[i];
      pre[i]->next[i] = p;
      if (rand() & 1) break;
    }
  }

  bool erase(int x) {
    vector<Node*> pre(level);
    find(x, pre);
    auto p = pre[0]->next[0];
    if (!p || p->val != x) return false;
    for (int i = 0; i < level && pre[i]->next[i] == p; i++)
      pre[i]->next[i] = p->next[i];
    delete p;
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
