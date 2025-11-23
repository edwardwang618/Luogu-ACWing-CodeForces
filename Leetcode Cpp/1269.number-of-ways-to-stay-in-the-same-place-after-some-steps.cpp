/*
 * @lc app=leetcode id=1269 lang=cpp
 *
 * [1269] Number of Ways to Stay in the Same Place After Some Steps
 */

// @lc code=start
class Solution {
 public:
  int numWays(int n, int m) {
    const int MOD = 1e9 + 7;
    m = min(n, m);
    vector<vector<int>> f(n + 1, vector<int>(m + 1));
    f[0][0] = 1;
    for (int i = 1; i <= n; i++)
      for (int j = 0; j < m; j++) {
        f[i][j] = f[i - 1][j];
        if (j - 1 >= 0) f[i][j] = (f[i][j] + f[i - 1][j - 1]) % MOD;
        if (j + 1 < m) f[i][j] = (f[i][j] + f[i - 1][j + 1]) % MOD;
      }
    return f[n][0];
  }
};
// @lc code=end
