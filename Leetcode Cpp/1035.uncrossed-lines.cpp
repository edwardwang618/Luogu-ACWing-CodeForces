/*
 * @lc app=leetcode id=1035 lang=cpp
 *
 * [1035] Uncrossed Lines
 */

// @lc code=start
class Solution {
 public:
  int maxUncrossedLines(vector<int>& a, vector<int>& b) {
    int m = a.size(), n = b.size();
    int f[m + 1][n + 1];
    memset(f, 0, sizeof f);
    for (int i = 1; i <= m; i++)
      for (int j = 1; j <= n; j++)
        f[i][j] = a[i - 1] == b[j - 1] ? 1 + f[i - 1][j - 1]
                                       : max(f[i - 1][j], f[i][j - 1]);

    return f[m][n];
  }
};
// @lc code=end
