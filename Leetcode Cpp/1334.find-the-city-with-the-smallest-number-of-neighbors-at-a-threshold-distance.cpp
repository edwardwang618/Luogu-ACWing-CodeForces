/*
 * @lc app=leetcode id=1334 lang=cpp
 *
 * [1334] Find the City With the Smallest Number of Neighbors at a Threshold
 * Distance
 */

// @lc code=start
class Solution {
 public:
  int findTheCity(int n, vector<vector<int>>& edges, int dt) {
    int d[n][n];
    memset(d, 0x3f, sizeof d);
    for (auto& e : edges) {
      int x = e[0], y = e[1];
      d[x][y] = d[y][x] = min(d[x][y], e[2]);
    }
    for (int k = 0; k < n; k++)
      for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
          d[i][j] = i == j ? 0 : min(d[i][j], d[i][k] + d[k][j]);

    int res = n, max_cnt = n;
    for (int i = 0; i < n; i++) {
      int cnt = 0;
      for (int j = 0; j < n; j++) {
        if (j == i) continue;
        if (d[i][j] <= dt) cnt++;
      }
      if (cnt <= max_cnt) {
        res = i;
        max_cnt = cnt;
      }
    }

    return res;
  }
};
// @lc code=end
