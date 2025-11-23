/*
 * @lc app=leetcode id=1284 lang=cpp
 *
 * [1284] Minimum Number of Flips to Convert Binary Matrix to Zero Matrix
 */

// @lc code=start
class Solution {
 public:
  int minFlips(vector<vector<int>>& g) {
    int m = g.size(), n = g[0].size();
    int d[] = {-1, 0, 1, 0, -1};
    int res = -1;
    for (int i = 0; i < 1 << n * m; i++) {
      auto w = g;
      int cnt = 0;
      for (int j = 0; j < n * m; j++)
        if (i >> j & 1) {
          cnt++;
          for (int k = 0; k < 4; k++) {
            int x = j / n + d[k], y = j % n + d[k + 1];
            if (0 <= x && x < m && 0 <= y && y < n) w[x][y] ^= 1;
          }
          w[j / n][j % n] ^= 1;
        }
      bool flag = true;
      for (int j = 0; j < m; j++)
        for (int k = 0; k < n; k++)
          if (w[j][k]) {
            flag = false;
            break;
          }
      if (flag && (!~res || res > cnt)) res = cnt;
    }

    return res;
  }
};
// @lc code=end
