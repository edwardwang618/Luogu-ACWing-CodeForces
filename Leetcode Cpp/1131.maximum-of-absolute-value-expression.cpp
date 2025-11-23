/*
 * @lc app=leetcode id=1131 lang=cpp
 *
 * [1131] Maximum of Absolute Value Expression
 */

// @lc code=start
class Solution {
 public:
  int maxAbsValExpr(vector<int>& a, vector<int>& b) {
    int res = 0, n = a.size();
    for (int i = -1; i <= 1; i += 2)
      for (int j = -1; j <= 1; j += 2) {
        int m = i * a[0] + j * b[0];
        for (int k = 1, cur; k < n; k++) {
          cur = i * a[k] + j * b[k] + k;
          res = max(res, cur - m);
          m = min(m, cur);
        }
      }
    return res;
  }
};
// @lc code=end
