/*
 * @lc app=leetcode id=516 lang=cpp
 *
 * [516] Longest Palindromic Subsequence
 */

// @lc code=start
class Solution {
public:
  int longestPalindromeSubseq(string &s) {
    int n = s.size();
    vector<vector<int>> f(2, vector<int>(n));
    for (int l = n - 1; l >= 0; l--)
      for (int r = l; r < n; r++) {
        int len = r - l + 1;
        if (len == 1) f[l & 1][l] = 1;
        else if (len == 2)
          f[l & 1][r] = s[l] == s[r] ? 2 : 1;
        else {
          f[l & 1][r] = f[l + 1 & 1][r - 1];
          if (s[l] == s[r]) f[l & 1][r] += 2;
          else f[l & 1][r] = max(f[l + 1 & 1][r], f[l & 1][r - 1]);
        }
      }
    return f[0][n - 1];
  }
};
// @lc code=end
