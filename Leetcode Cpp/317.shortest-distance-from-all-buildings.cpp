/*
 * @lc app=leetcode id=317 lang=cpp
 *
 * [317] Shortest Distance from All Buildings
 */

// @lc code=start
class Solution {
 public:
  using PII = pair<int, int>;
#define x first
#define y second
  int shortestDistance(vector<vector<int>>& g) {
    int m = g.size(), n = g[0].size();
    int sum_dist[m][n];
    memset(sum_dist, 0, sizeof sum_dist);
    auto bfs = [&](int x, int y) {
      bool vis[m][n];
      memset(vis, 0, sizeof vis);
      vis[x][y] = true;
      queue<PII> q;
      q.push({x, y});
      int step = 0;
      while (q.size()) {
        step++;
        for (int _ = q.size(); _; _--) {
          auto p = q.front(); q.pop();
          int x = p.x, y = p.y;
          static int d[] = {-1, 0, 1, 0, -1};
          for (int k = 0; k < 4; k++) {
            int nx = x + d[k], ny = y + d[k + 1];
            if (0 <= nx && nx < m && 0 <= ny && ny < n && !vis[nx][ny] &&
                !g[nx][ny]) {
              vis[nx][ny] = true;
              q.push({nx, ny});
              if (~sum_dist[nx][ny]) sum_dist[nx][ny] += step;
            }
          }
        }
      }

      for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
          if (!g[i][j] && !vis[i][j]) sum_dist[i][j] = -1;
    };
    
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        if (g[i][j] == 1) bfs(i, j);

    int res = INT_MAX;
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        if (!g[i][j] && ~sum_dist[i][j]) res = min(res, sum_dist[i][j]);

    return res == INT_MAX ? -1 : res;
  }
};
// @lc code=end
