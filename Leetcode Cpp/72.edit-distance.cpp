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
    if (m < n) {
      swap(s1, s2);
      swap(m, n);
    }
    int f[2][n + 1];
    iota(&f[0][0], &f[0][0] + n + 1, 0);
    for (int i = 1; i <= m; i++)
      for (int j = 0; j <= n; j++) {
        if (!j)
          f[i & 1][j] = i;
        else {
          if (s1[i - 1] == s2[j - 1])
            f[i & 1][j] = f[i - 1 & 1][j - 1];
          else {
            int ins = f[i & 1][j - 1] + 1;
            int rep = f[i - 1 & 1][j - 1] + 1;
            int del = f[i - 1 & 1][j] + 1;
            f[i & 1][j] = min({ins, rep, del});
          }
        }
      }

    return f[m & 1][n];
  }
};
// @lc code=end
