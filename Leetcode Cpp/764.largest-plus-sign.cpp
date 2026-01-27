/*
 * @lc app=leetcode id=764 lang=cpp
 *
 * [764] Largest Plus Sign
 */

// @lc code=start
class Solution {
public:
  int orderOfLargestPlusSign(int n, vector<vector<int>> &mines) {
    vector g(n, vector<int>(n, 1));
    for (auto &x : mines) g[x[0]][x[1]] = 0;
    vector f(n, vector<int>(n, n));
    for (int i = 0; i < n; i++) {
      int cnt_l = 0, cnt_r = 0;
      for (int j = 0; j < n; j++) {
        cnt_l = g[i][j] ? cnt_l + 1 : 0;
        f[i][j] = min(f[i][j], cnt_l);
        cnt_r = g[i][n - 1 - j] ? cnt_r + 1 : 0;
        f[i][n - 1 - j] = min(f[i][n - 1 - j], cnt_r);
      }
    }
    for (int j = 0; j < n; j++) {
      int cnt_u = 0, cnt_d = 0;
      for (int i = 0; i < n; i++) {
        cnt_u = g[i][j] ? cnt_u + 1 : 0;
        f[i][j] = min(f[i][j], cnt_u);
        cnt_d = g[n - 1 - i][j] ? cnt_d + 1 : 0;
        f[n - 1 - i][j] = min(f[n - 1 - i][j], cnt_d);
      }
    }

    int res = 0;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        res = max(res, f[i][j]);
    return res;
  }
};
// @lc code=end
