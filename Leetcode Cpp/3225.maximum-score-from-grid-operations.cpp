/*
 * @lc app=leetcode id=3225 lang=cpp
 *
 * [3225] Maximum Score From g Operations
 */

// @lc code=start
class Solution {
 public:
  using ll = long long;
  ll maximumScore(vector<vector<int>>& g) {
    int n = g.size();
    ll f[n + 1][n + 1][2];
    memset(f, 0, sizeof(f));

    vector<vector<ll>> sum(n, vector<ll>(n + 1));
    for (int i = 0; i < n; i++) {
      sum[i][0] = 0;
      for (int j = 1; j <= n; j++) sum[i][j] = sum[i][j - 1] + g[j - 1][i];
    }

    for (int i = 1; i < n; i++)
      for (int j = 0; j <= n; j++) {
        for (int k = 0; k <= j; k++) {
          ll t = max(f[i - 1][k][0],
                     f[i - 1][k][1] + sum[i - 1][j] - sum[i - 1][k]);
          f[i][j][0] = f[i][j][1] = max(f[i][j][0], t);
        }

        for (int k = j + 1; k <= n; k++) {
          ll t = f[i - 1][k][0];
          f[i][j][0] = max(f[i][j][0], t + sum[i][k] - sum[i][j]);
          f[i][j][1] = max(f[i][j][1], t);
        }
      }

    ll res = 0;
    for (int j = 0; j <= n; j++) res = max(res, f[n - 1][j][0]);

    return res;
  }
};
// @lc code=end
