/*
 * @lc app=leetcode id=1292 lang=cpp
 *
 * [1292] Maximum Side Length of a Square with Sum Less than or Equal to
 * Threshold
 */

// @lc code=start
class Solution {
 public:
  int maxSideLength(vector<vector<int>>& g, int threshold) {
    int m = g.size(), n = g[0].size();
    int s[m + 1][n + 1];
    memset(s, 0, sizeof s);
    for (int i = 1; i <= m; i++)
      for (int j = 1; j <= n; j++)
        s[i][j] = g[i - 1][j - 1] + s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
    auto f = [&](int x1, int y1, int x2, int y2) {
      return s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1];
    };
    int res = 0;
    for (int i = 1; i <= m; i++)
      for (int j = 1; j <= n; j++)
        for (int k = res + 1; k <= min(i, j); k++) {
          if (f(i - k + 1, j - k + 1, i, j) > threshold) break;
          res++;
        }
    return res;
  }
};
// @lc code=end
