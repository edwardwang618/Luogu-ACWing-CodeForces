/*
 * @lc app=leetcode id=2533 lang=cpp
 *
 * [2533] Number of Good Binary Strings
 */

// @lc code=start
class Solution {
 public:
  int goodBinaryStrings(int minL, int maxL, int one, int zero) {
    constexpr int MOD = 1e9 + 7;
    vector<int> f(maxL + 1, 0);
    f[0] = 1;
    int res = 0;
    for (int i = 1; i <= maxL; i++) {
      if (i >= one) f[i] = (f[i] + f[i - one]) % MOD;
      if (i >= zero) f[i] = (f[i] + f[i - zero]) % MOD;
      if (i >= minL) res = (res + f[i]) % MOD;
    }
    return res;
  }
};
// @lc code=end
