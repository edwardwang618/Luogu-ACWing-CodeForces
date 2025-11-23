/*
 * @lc app=leetcode id=664 lang=cpp
 *
 * [664] Strange Printer
 */

// @lc code=start
class Solution {
 public:
  int strangePrinter(string s) {
    int n = 0;
    for (int i = 0; i < s.size(); i++)
      if (!n || s[i] != s[n - 1]) s[n++] = s[i];
    s.resize(n);

    int f[n][n];
    for (int len = 1; len <= n; len++)
      for (int l = 0; l + len - 1 < n; l++) {
        int r = l + len - 1;
        if (len == 1) f[l][r] = 1;
        else {
          f[l][r] = 1 + f[l + 1][r];
          for (int i = l + 1; i <= r; i++)
            if (s[i] == s[l])
              f[l][r] = min(f[l][r], f[l][i - 1] + (i + 1 <= r ? f[i + 1][r] : 0));
        }
      }

    return f[0][n - 1];
  }
};
// @lc code=end
