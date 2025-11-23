/*
 * @lc app=leetcode id=221 lang=cpp
 *
 * [221] Maximal Square
 */

// @lc code=start
class Solution {
 public:
  int maximalSquare(vector<vector<char>>& A) {
    int res = 0, m = A.size(), n = A[0].size();
    int f[m + 1][n + 1];
    memset(f, 0, sizeof f);
    for (int i = 1; i <= m; i++)
      for (int j = 1; j <= n; j++) {
        if (A[i - 1][j - 1] != '0') {
          f[i][j] = min(f[i - 1][j - 1], min(f[i - 1][j], f[i][j - 1])) + 1;
          res = max(res, f[i][j]);
        }
      }

    return res * res;
  }
};
// @lc code=end
