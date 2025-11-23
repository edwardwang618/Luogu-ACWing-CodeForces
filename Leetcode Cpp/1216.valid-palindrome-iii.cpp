/*
 * @lc app=leetcode id=1216 lang=cpp
 *
 * [1216] Valid Palindrome III
 */

// @lc code=start
class Solution {
 public:
  bool isValidPalindrome(string s, int k) {
    int n = s.size();
    int f[n][n];
    memset(f, 0, sizeof f);
    for (int len = 2; len <= n; len++)
      for (int l = 0; l + len - 1 < n; l++) {
        int r = l + len - 1;
        if (len == 2) f[l][r] = s[l] != s[r];
        else {
          if (s[l] == s[r]) f[l][r] = f[l + 1][r - 1];
          else f[l][r] = 1 + min(f[l + 1][r], f[l][r - 1]);
        }
      }

    return f[0][n - 1] <= k;
  }
};
// @lc code=end
