/*
 * @lc app=leetcode id=712 lang=cpp
 *
 * [712] Minimum ASCII Delete Sum for Two Strings
 */

// @lc code=start
class Solution {
 public:
  int minimumDeleteSum(string s1, string s2) {
    int m = s1.size(), n = s2.size();
    s1 = " " + s1, s2 = " " + s2;
    int f[m + 1][n + 1];
    memset(f, 0x3f, sizeof f);
    f[0][0] = 0;
    for (int i = 0; i <= m; i++)
      for (int j = 0; j <= n; j++) {
        if (!i && !j) continue;
        if (!i) f[i][j] = f[i][j - 1] + s2[j];
        else if (!j) f[i][j] = f[i - 1][j] + s1[i];
        else {
          f[i][j] = min(f[i - 1][j] + s1[i], f[i][j - 1] + s2[j]);
          if (s1[i] == s2[j]) f[i][j] = min(f[i][j], f[i - 1][j - 1]);
          else f[i][j] = min(f[i][j], f[i - 1][j - 1] + s1[i] + s2[j]);
        }
      }
    return f[m][n];
  }
};
// @lc code=end
