/*
 * @lc app=leetcode id=1682 lang=cpp
 *
 * [1682] Longest Palindromic Subsequence II
 */

// @lc code=start
class Solution {
 public:
  int longestPalindromeSubseq(string s) {
    int n = s.size(), f[n][n][26];
    memset(f, 0, sizeof f);
    for (int len = 2; len <= n; len++)
      for (int l = 0; l + len - 1 < n; l++) {
        int r = l + len - 1;
        for (int k = 0; k < 26; k++)
          f[l][r][k] = max(f[l + 1][r][k], f[l][r - 1][k]);
        if (s[l] == s[r]) {
          int x = s[l] - 'a';
          for (int k = 0; k < 26; k++)
            if (x != k) f[l][r][x] = max(f[l][r][x], 2 + f[l + 1][r - 1][k]);
        }
      }

    int res = 0;
    for (int len = 2; len <= n; len++)
      for (int l = 0; l + len - 1 < n; l++)
        for (int k = 0; k < 26; k++) res = max(res, f[l][l + len - 1][k]);

    return res;
  }
};
// @lc code=end
