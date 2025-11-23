/*
 * @lc app=leetcode id=891 lang=cpp
 *
 * [891] Sum of Subsequence Widths
 */

// @lc code=start
class Solution {
 public:
  int sumSubseqWidths(vector<int>& a) {
    const int MOD = 1e9 + 7;
    sort(a.begin(), a.end());
    int n = a.size();
    long f[n];
    f[0] = 1;
    for (int i = 1; i < n; i++) f[i] = 2 * f[i - 1] % MOD;

    long res = 0;
    for (int i = 0; i < n; i++)
      res = (res + (f[i] - f[n - 1 - i]) * a[i]) % MOD;

    return (res + MOD) % MOD;
  }
};
// @lc code=end
