/*
 * @lc app=leetcode id=629 lang=cpp
 *
 * [629] K Inverse Pairs Array
 */

// @lc code=start
class Solution {
 public:
  int kInversePairs(int n, int k) {
    const int MOD = 1e9 + 7;
    vector<vector<int>> f(n + 1, vector<int>(k + 1));
    f[1][0] = 1;
    for (int i = 2; i <= n; i++)
      for (int j = 0, s = 0; j <= k; j++) {
        s = (s + f[i - 1][j]) % MOD;
        if (j >= i) s = (s + MOD - f[i - 1][j - i]) % MOD;
        f[i][j] = s;
      }

    return f[n][k];
  }
};
// @lc code=end
