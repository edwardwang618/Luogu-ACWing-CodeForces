/*
 * @lc app=leetcode id=994 lang=cpp
 *
 * [994] Rotting Oranges
 */

// @lc code=start
class Solution {
public:
  using PII = pair<int, int>;
  int orangesRotting(vector<vector<int>> &g) {
    queue<PII> q;
    int m = g.size(), n = g[0].size();
    int fresh = 0;
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        if (g[i][j] == 2) q.push({i, j});
        else if (g[i][j] == 1) fresh++;
    int res = 0;
    while (q.size()) {
      for (int i = q.size(); i; i--) {
        auto [x, y] = q.front(); q.pop();
        static int d[] = {1, 0, -1, 0, 1};
        for (int k = 0; k < 4; k++) {
          int nx = x + d[k], ny = y + d[k + 1];
          if (0 <= nx && nx < m && 0 <= ny && ny < n && g[nx][ny] == 1) {
            g[nx][ny] = 2;
            fresh--;
            q.push({nx, ny});
          }
        }
      }
      if (q.size()) res++;
    }

    return fresh ? -1 : res;
  }
};
// @lc code=end
