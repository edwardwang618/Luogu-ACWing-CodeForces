/*
 * @lc app=leetcode id=1259 lang=cpp
 *
 * [1259] Handshakes That Don't Cross
 */

// @lc code=start
class Solution {
 public:
  int numberOfWays(int n) {
    int MOD = 1e9 + 7;
    n >>= 1;
    long f[n + 1];
    memset(f, 0, sizeof f);
    f[0] = 1;
    for (int k = 1; k <= n; k++)
      for (int x = 0; x < k; x++) f[k] = (f[k] + f[x] * f[k - 1 - x]) % MOD;

    return f[n];
  }
};
// @lc code=end
