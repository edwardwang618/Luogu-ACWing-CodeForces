/*
 * @lc app=leetcode id=2472 lang=cpp
 *
 * [2472] Maximum Number of Non-overlapping Palindrome Substrings
 */

// @lc code=start
class Solution {
 public:
  int maxPalindromes(string s, int k) {
    int n = s.size();
    bool g[n + 1][n + 1];
    memset(g, 1, sizeof g);
    for (int len = 1; len <= n; len++)
      for (int l = 0; l + len - 1 < n; l++) {
        int r = l + len - 1;
        if (len == 1)
          g[l][r] = true;
        else if (len == 2)
          g[l][r] = s[l] == s[r];
        else
          g[l][r] = s[l] == s[r] ? g[l + 1][r - 1] : false;
      }

    vector<int> f(n + 1, 0);
    for (int i = k - 1; i < n; i++) {
      f[i + 1] = f[i];
      if (g[i - k + 1][i]) f[i + 1] = max(f[i + 1], 1 + f[i - k + 1]);
      if (i - k >= 0 && g[i - k][i]) f[i + 1] = max(f[i + 1], 1 + f[i - k]);
    }

    return f[n];
  }
};
// @lc code=end
