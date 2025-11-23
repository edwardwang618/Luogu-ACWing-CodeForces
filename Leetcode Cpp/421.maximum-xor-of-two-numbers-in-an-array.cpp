/*
 * @lc app=leetcode id=421 lang=cpp
 *
 * [421] Maximum XOR of Two Numbers in an Array
 */

// @lc code=start
class Solution {
 public:
  struct Node {
    Node* ne[2];
    Node() { fill(ne, ne + 2, nullptr); }
  };

  Node* root;

  void add(int x) {
    auto *p = root;
    for (int i = 30; i >= 0; i--) {
      int idx = x >> i & 1;
      if (!p->ne[idx]) p->ne[idx] = new Node();
      p = p->ne[idx];
    }
  }

  int query(int x) {
    int res = 0;
    auto *p = root;
    for (int i = 30; i >= 0; i--) {
      int idx = x >> i & 1;
      if (p->ne[idx ^ 1]) {
        res |= 1 << i;
        p = p->ne[idx ^ 1];
      } else p = p->ne[idx];
    }

    return res;
  }

  int findMaximumXOR(vector<int>& a) {
    root = new Node();
    int res = 0;
    for (int x : a) {
      add(x);
      res = max(res, query(x));
    }

    return res;
  }
};
// @lc code=end
