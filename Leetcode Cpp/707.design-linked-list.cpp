/*
 * @lc app=leetcode id=707 lang=cpp
 *
 * [707] Design Linked List
 */

// @lc code=start
class MyLinkedList {
  static constexpr int null = -1;
  static constexpr int head = 0;
  static constexpr int tail = 1;
  struct Node {
    int prev, next;
    int val;
    Node(int x) : prev(null), next(null), val(x) {}
    Node(int x, int prev, int next) : prev(prev), next(next), val(x) {}
  };

  vector<Node> pl;
  vector<int> used;
  int sz;

#define prev(idx) pl[idx].prev
#define next(idx) pl[idx].next
#define val(idx) pl[idx].val

  int new_node(int val) {
    int idx;
    if (used.size()) {
      idx = used.back();
      used.pop_back();
      pl[idx].val = val;
    } else {
      idx = pl.size();
      pl.emplace_back(val);
    }
    return idx;
  }

  int operator[](int idx) {
    if (idx < 0 || idx >= sz)
      return null;
    int res;
    if (idx < sz >> 1) {
      res = head;
      for (int i = 0; i <= idx; i++)
        res = next(res);
    } else {
      res = tail;
      for (int i = sz; i > idx; i--)
        res = prev(res);
    }
    return res;
  }

public:
  MyLinkedList() {
    pl.reserve(2);
    pl.emplace_back(0);
    pl.emplace_back(0);
    next(head) = tail;
    prev(tail) = head;
    sz = 0;
  }

  int get(int idx) {
    if (idx = (*this)[idx]; ~idx)
      return val(idx);
    return -1;
  }

  void addAtHead(int val) {
    int idx = new_node(val);
    prev(idx) = head;
    next(idx) = next(head);
    next(head) = idx;
    prev(next(idx)) = idx;
    sz++;
  }

  void addAtTail(int val) {
    int idx = new_node(val);
    prev(idx) = prev(tail);
    next(idx) = tail;
    prev(tail) = idx;
    next(prev(idx)) = idx;
    sz++;
  }

  void addAtIndex(int idx, int val) {
    if (idx == sz) {
      addAtTail(val);
      return;
    }
    if (idx < 0 || idx > sz)
      return;
    int new_idx = new_node(val);
    idx = (*this)[idx];
    prev(new_idx) = prev(idx);
    next(new_idx) = idx;
    prev(idx) = new_idx;
    next(prev(new_idx)) = new_idx;
    sz++;
  }

  void deleteAtIndex(int idx) {
    if (idx = (*this)[idx]; ~idx) {
      prev(next(idx)) = prev(idx);
      next(prev(idx)) = next(idx);
      used.push_back(idx);
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
