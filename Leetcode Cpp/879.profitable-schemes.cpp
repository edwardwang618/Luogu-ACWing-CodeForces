/*
 * @lc app=leetcode id=879 lang=cpp
 *
 * [879] Profitable Schemes
 */

// @lc code=start
class Solution {
 public:
  int profitableSchemes(int n, int m, vector<int>& g, vector<int>& p) {
    const int MOD = 1e9 + 7;
    int f[g.size() + 1][n + 1][m + 1];
    memset(f, 0, sizeof f);
    for (int j = 0; j <= n; j++) f[0][j][0] = 1;
    for (int i = 1; i <= g.size(); i++)
      for (int j = 0; j <= n; j++)
        for (int k = 0; k <= m; k++) {
          f[i][j][k] = f[i - 1][j][k];
          if (j >= g[i - 1])
            f[i][j][k] = (f[i][j][k] + f[i - 1][j - g[i - 1]][max(k - p[i - 1], 0)]) % MOD;
        }

    return f[g.size()][n][m];
  }
};
// @lc code=end
