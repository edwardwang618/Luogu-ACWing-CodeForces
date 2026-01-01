/*
 * @lc app=leetcode id=3286 lang=cpp
 *
 * [3286] Find a Safe Walk Through a Grid
 */

// @lc code=start
class Solution {
public:
  bool findSafeWalk(vector<vector<int>> &g, int h) {
    int m = g.size(), n = g[0].size();
    auto id = [&](int x, int y) {
      return x * n + y;
    };
    vector<vector<int>> dist(m, vector<int>(n, 2e9));
    dist[m - 1][n - 1] = g[m - 1][n - 1];
    using PII = pair<int, int>;
    deque<PII> dq;
    dq.emplace_back(dist[m - 1][n - 1], id(m - 1, n - 1));
    while (dq.size()) {
      auto [dis, i] = dq.front(); dq.pop_front();
      int x = i / n, y = i % n;
      if (dis > dist[x][y]) continue;
      if (!i) break;
      static int d[] = {1, 0, -1, 0, 1};
      for (int k = 0; k < 4; k++) {
        int nx = x + d[k], ny = y + d[k + 1];
        if (0 <= nx && nx < m && 0 <= ny && ny < n) {
          int idxy = id(nx, ny);
          if (!g[nx][ny] && dist[nx][ny] > dis) {
            dist[nx][ny] = dis;
            dq.emplace_front(dis, idxy);
          }
          if (g[nx][ny] && dist[nx][ny] > dis + 1) {
            dist[nx][ny] = dis + 1;
            dq.emplace_back(dis + 1, idxy);
          }
        }
      }
    }
    return dist[0][0] < h;
  }
};
// @lc code=end
