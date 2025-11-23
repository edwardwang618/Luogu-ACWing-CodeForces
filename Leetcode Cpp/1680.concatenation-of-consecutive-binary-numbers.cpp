/*
 * @lc app=leetcode id=1680 lang=cpp
 *
 * [1680] Concatenation of Consecutive Binary Numbers
 */

// @lc code=start
class Solution {
 public:
  int concatenatedBinary(int n) {
    static const int MOD = 1e9 + 7;
    if (n == 1) return 1;
    long x = concatenatedBinary(n - 1);
    int cnt = 0, m = n;
    while (m) cnt++, m >>= 1;
    return ((x << cnt) + n) % MOD;
  }
};
// @lc code=end
