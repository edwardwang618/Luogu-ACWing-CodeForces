/*
 * @lc app=leetcode id=1314 lang=cpp
 *
 * [1314] Matrix Block Sum
 */

// @lc code=start
class Solution {
 public:
  vector<vector<int>> matrixBlockSum(vector<vector<int>>& g, int k) {
    int m = g.size(), n = g[0].size();
    int f[m + 1][n + 1];
    memset(f, 0, sizeof f);
    for (int i = 1; i <= m; i++)
      for (int j = 1; j <= n; j++)
        f[i][j] = f[i - 1][j] + f[i][j - 1] + g[i - 1][j - 1] - f[i - 1][j - 1];

    vector<vector<int>> res(m, vector<int>(n));
    for (int i = 1; i <= m; i++)
      for (int j = 1; j <= n; j++) {
        int x1 = max(1, i - k), y1 = max(1, j - k), x2 = min(m, i + k),
            y2 = min(n, j + k);
        res[i - 1][j - 1] =
            f[x2][y2] - f[x2][y1 - 1] - f[x1 - 1][y2] + f[x1 - 1][y1 - 1];
      }

    return res;
  }
};
// @lc code=end
