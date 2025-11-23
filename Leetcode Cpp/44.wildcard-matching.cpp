/*
 * @lc app=leetcode id=44 lang=cpp
 *
 * [44] Wildcard Matching
 */

// @lc code=start
class Solution {
 public:
  bool isMatch(string s, string p) {
    int m = s.size(), n = p.size();
    bool f[m + 1][n + 1];
    memset(f, 0, sizeof f);
    f[0][0] = true;
    for (int i = 0; i <= m; i++)
      for (int j = 1; j <= n; j++) {
        if (i && p[j - 1] != '*')
          f[i][j] =
              f[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '?');
        if (p[j - 1] == '*') f[i][j] = f[i][j - 1] || (i && f[i - 1][j]);
      }

    return f[m][n];
  }
};
// @lc code=end
