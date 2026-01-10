/*
 * @lc app=leetcode id=3043 lang=cpp
 *
 * [3043] Find the Length of the Longest Common Prefix
 */

// @lc code=start
class Solution {
public:
  struct Node {
    int ne[10]{};
  };

  vector<Node> tr;

  int new_node() {
    int n = tr.size();
    tr.emplace_back();
    return n;
  }
#define root 0

  void insert(string x) {
    int p = root;
    for (int i = 0; i < x.size(); i++) {
      int idx = x[i] - '0';
      if (!tr[p].ne[idx])
        tr[p].ne[idx] = new_node();
      p = tr[p].ne[idx];
    }
  }

  int calc(string x) {
    int res = 0;
    int p = root;
    for (int i = 0; i < x.size(); i++) {
      int idx = x[i] - '0';
      if (tr[p].ne[idx]) p = tr[p].ne[idx], res++;
      else break;
    }
    return res;
  }

  int longestCommonPrefix(vector<int> &a1, vector<int> &a2) {
    tr.emplace_back();
    for (int x : a1) insert(to_string(x));
    int res = 0;
    for (int x : a2)
      res = max(res, calc(to_string(x)));
    return res;
  }
};
// @lc code=end
