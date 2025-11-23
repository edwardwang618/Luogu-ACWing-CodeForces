/*
 * @lc app=leetcode id=1463 lang=cpp
 *
 * [1463] Cherry Pickup II
 */

// @lc code=start
class Solution {
 public:
  int cherryPickup(vector<vector<int>>& g) {
    int m = g.size(), n = g[0].size();
    int f[m][n][n];
    memset(f, -1, sizeof f);
    f[0][0][n - 1] = g[0][0];
    if (n > 1) f[0][0][n - 1] += g[0][n - 1];

    for (int k = 0; k < m - 1; k++)
      for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
          if (~f[k][i][j])
            for (int di = -1; di <= 1; di++)
              for (int dj = -1; dj <= 1; dj++) {
                int ni = i + di, nj = j + dj;
                if (0 <= ni && ni < n && 0 <= nj && nj < n) {
                  int x = g[k + 1][ni];
                  if (ni != nj) x += g[k + 1][nj];
                  f[k + 1][ni][nj] = max(f[k + 1][ni][nj], f[k][i][j] + x);
                }
              }

    int res = 0;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++) res = max(res, f[m - 1][i][j]);
    return res;
  }
};
// @lc code=end
