/*
 * @lc app=leetcode id=3043 lang=cpp
 *
 * [3043] Find the Length of the Longest Common Prefix
 */

// @lc code=start

class Solution {
 public:
  struct Node {
    Node* ne[10];
    Node() {
      for (int i = 0; i < 10; i++) ne[i] = nullptr;
    }
  };

  Node* root;

  void insert(string&& x) {
    auto p = root;
    for (int i = 0; i < x.size(); i++) {
      int idx = x[i] - '0';
      if (!p->ne[idx]) p->ne[idx] = new Node();
      p = p->ne[idx];
    }
  }

  int calc(string&& x) {
    int res = 0;
    auto p = root;
    for (int i = 0; i < x.size(); i++) {
      int idx = x[i] - '0';
      if (p->ne[idx])
        p = p->ne[idx], res++;
      else
        break;
    }
    return res;
  }

  int longestCommonPrefix(vector<int>& a1, vector<int>& a2) {
    root = new Node();
    for (int x : a1) insert(to_string(x));
    int res = 0;
    for (int x : a2) res = max(res, calc(to_string(x)));
    return res;
  }
};
// @lc code=end
