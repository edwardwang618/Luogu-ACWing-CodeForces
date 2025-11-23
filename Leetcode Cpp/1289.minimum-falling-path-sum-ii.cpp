/*
 * @lc app=leetcode id=1289 lang=cpp
 *
 * [1289] Minimum Falling Path Sum II
 */

// @lc code=start
class Solution {
 public:
  int minFallingPathSum(vector<vector<int>>& g) {
    int n = g.size();
    int f[n][n];
    memset(f, 0, sizeof f);
    for (int i = 0; i < n; i++) f[0][i] = g[0][i];
    for (int i = 1; i < n; i++) {
      int m1 = 2e9, m2 = 2e9;
      for (int j = 0; j < n; j++)
        if (f[i - 1][j] <= m1)
          m2 = m1, m1 = f[i - 1][j];
        else if (f[i - 1][j] < m2)
          m2 = f[i - 1][j];

      for (int j = 0; j < n; j++)
        if (f[i - 1][j] == m1)
          f[i][j] = m2 + g[i][j];
        else
          f[i][j] = m1 + g[i][j];
    }

    int res = 2e9;
    for (int i = 0; i < n; i++) res = min(res, f[n - 1][i]);
    return res;
  }
};
// @lc code=end
