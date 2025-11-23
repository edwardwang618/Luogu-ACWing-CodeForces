/*
 * @lc app=leetcode id=1143 lang=cpp
 *
 * [1143] Longest Common Subsequence
 */

// @lc code=start
class Solution {
 public:
  int longestCommonSubsequence(string s1, string s2) {
    int n = s1.size(), m = s2.size(); 
    int f[n + 1][m + 1];
    memset(f, 0, sizeof f);
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++)
        if (s1[i - 1] == s2[j - 1]) f[i][j] = 1 + f[i - 1][j - 1];
        else f[i][j] = max(f[i][j - 1], f[i - 1][j]);
    return f[n][m];
  }
};
// @lc code=end
