/*
 * @lc app=leetcode id=10 lang=cpp
 *
 * [10] Regular Expression Matching
 */

// @lc code=start
class Solution {
public:
  bool isMatch(string s, string p) {
    int n = s.size(), m = p.size();
    s = " " + s;
    p = " " + p;
    bool f[n + 1][m + 1];
    memset(f, 0, sizeof f);
    f[0][0] = true;
    auto g = [&](int i, int j) { return s[i] == p[j] || p[j] == '.'; };
    for (int i = 0; i <= n; i++)
      for (int j = 1; j <= m; j++)
        if (p[j] != '*')
          f[i][j] = i && g(i, j) && f[i - 1][j - 1];
        else
          f[i][j] = j >= 2 && f[i][j - 2] || i && f[i - 1][j] && g(i, j - 1);
    return f[n][m];
  }
};
// @lc code=end
