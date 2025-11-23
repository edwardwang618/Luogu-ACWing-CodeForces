/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */

// @lc code=start
class Solution {
 public:
  vector<string> generateParenthesis(int n) {
    vector<string> res;
    string s;
    dfs(s, 0, 0, res, n);
    return res;
  }

  void dfs(string& s, int l, int r, vector<string>& res, int n) {
    if (r == n) {
      res.push_back(s);
      return;
    }

    if (l < n) {
      s += '(';
      dfs(s, l + 1, r, res, n);
      s.pop_back();
    }
    if (l > r) {
      s += ')';
      dfs(s, l, r + 1, res, n);
      s.pop_back();
    }
  }
};
// @lc code=end
