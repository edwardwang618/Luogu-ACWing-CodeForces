/*
 * @lc app=leetcode id=72 lang=cpp
 *
 * [72] Edit Distance
 */

// @lc code=start
class Solution {
 public:
  int minDistance(string s1, string s2) {
    int m = s1.size(), n = s2.size();
    int f[m + 1][n + 1];
    for (int i = 0; i <= m; i++)
      for (int j = 0; j <= n; j++) {
        if (!i || !j) f[i][j] = i ^ j;
        else {
          if (s1[i - 1] == s2[j - 1]) f[i][j] = f[i - 1][j - 1];
          else {
            f[i][j] = min(f[i][j - 1] + 1, f[i - 1][j - 1] + 1);
            f[i][j] = min(f[i][j], 1 + f[i - 1][j]);
          }
        }
      }

    return f[m][n];
  }
};
// @lc code=end
