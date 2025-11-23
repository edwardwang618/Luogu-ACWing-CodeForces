/*
 * @lc app=leetcode id=1312 lang=cpp
 *
 * [1312] Minimum Insertion Steps to Make a String Palindrome
 */

// @lc code=start
class Solution {
 public:
  int minInsertions(string s) {
    int n = s.size();
    int f[n][n];
    memset(f, 0, sizeof f);
    for (int len = 2; len <= n; len++)
      for (int l = 0; l + len - 1 < n; l++) {
        int r = l + len - 1;
        if (s[l] == s[r]) f[l][r] = f[l + 1][r - 1];
        else f[l][r] = min(f[l + 1][r], f[l][r - 1]) + 1;  
      }

    return f[0][n - 1];
  }
};
// @lc code=end
