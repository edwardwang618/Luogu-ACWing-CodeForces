/*
 * @lc app=leetcode id=967 lang=cpp
 *
 * [967] Numbers With Same Consecutive Differences
 */

// @lc code=start
class Solution {
 public:
  int n, k;
  vector<int> numsSameConsecDiff(int _n, int _k) {
    n = _n, k = _k;
    vector<int> res;
    dfs(0, 0, res);
    return res;
  }

  void dfs(int i, int x, vector<int> &res) {
    if (i == n) {
      res.push_back(x);
      return;
    }

    if (!i) {
      for (int j = 1; j <= 9; j++) dfs(i + 1, j, res);
    } else {
      int y = x % 10;
      if (y + k <= 9) dfs(i + 1, x * 10 + y + k, res);
      if (k && y - k >= 0) dfs(i + 1, x * 10 + y - k, res);
    }
  }
};
// @lc code=end
