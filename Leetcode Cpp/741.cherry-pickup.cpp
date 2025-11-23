/*
 * @lc app=leetcode id=741 lang=cpp
 *
 * [741] Cherry Pickup
 */

// @lc code=start
class Solution {
 public:
  int cherryPickup(vector<vector<int>>& g) {
    int n = g.size(), f[2 * n - 1][n][n];
    memset(f, -1, sizeof f);
    for (int k = 0; k < 2 * n - 1; k++)
      for (int i1 = 0; i1 < n; i1++)
        for (int i2 = 0; i2 < n; i2++) {
          int j1 = k - i1, j2 = k - i2;
          if (0 <= j1 && j1 < n && 0 <= j2 && j2 < n && ~g[i1][j1] &&
              ~g[i2][j2]) {
            if (!k)
              f[0][0][0] = g[0][0];
            else {
              int t = -1;
              if (j1 && j2) t = max(t, f[k - 1][i1][i2]);
              if (i1 && i2) t = max(t, f[k - 1][i1 - 1][i2 - 1]);
              if (j1 && i2) t = max(t, f[k - 1][i1][i2 - 1]);
              if (i1 && j2) t = max(t, f[k - 1][i1 - 1][i2]);
              if (~t) {
                t += g[i1][j1] + g[i2][j2];
                if (i1 == i2 && j1 == j2) t -= g[i1][j1];
                f[k][i1][i2] = t;
              }
            }
          }
        }

    return ~f[2 * n - 2][n - 1][n - 1] ? f[2 * n - 2][n - 1][n - 1] : 0;
  }
};
// @lc code=end
