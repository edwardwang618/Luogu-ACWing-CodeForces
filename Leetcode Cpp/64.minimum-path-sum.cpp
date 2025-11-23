/*
 * @lc app=leetcode id=64 lang=cpp
 *
 * [64] Minimum Path Sum
 */

// @lc code=start
class Solution {
 public:
  int minPathSum(vector<vector<int>>& g) {
    int n = g.size(), m = g[0].size();
    // 这里采取的是一行一行更新
    for (int j = 1; j < m; j++) g[0][j] += g[0][j - 1];

    for (int i = 1; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (j == 0)
          g[i][j] += g[i - 1][j];
        else
          g[i][j] += min(g[i - 1][j], g[i][j - 1]);
      }
    }

    return g[n - 1][m - 1];
  }
};
// @lc code=end
