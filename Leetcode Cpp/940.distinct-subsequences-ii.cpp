/*
 * @lc app=leetcode id=940 lang=cpp
 *
 * [940] Distinct Subsequences II
 */

// @lc code=start
class Solution {
 public:
  int distinctSubseqII(string s) {
    int MOD = 1e9 + 7;
    int n = s.size(), f[26] = {};
    for (int i = 1; i <= n; i++) {
      int t = 1;
      for (int k = 0; k < 26; k++) t = (t + f[k]) % MOD;
      f[s[i - 1] - 'a'] = t;
    }

    int res = 0;
    for (int x : f) res = (res + x) % MOD;
    return res;
  }
};
// @lc code=end
