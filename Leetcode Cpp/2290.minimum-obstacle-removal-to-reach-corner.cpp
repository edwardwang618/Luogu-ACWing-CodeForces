/*
 * @lc app=leetcode id=2290 lang=cpp
 *
 * [2290] Minimum Obstacle Removal to Reach Corner
 */

// @lc code=start
class Solution {
public:
  int minimumObstacles(vector<vector<int>> &g) {
    int m = g.size(), n = g[0].size();
    auto id = [&](int x, int y) {
      return x * n + y;
    };
    deque<int> dq;
    dq.push_front(0);
    constexpr int INF = 2e9;
    vector<int> dist(m * n, INF);
    dist[0] = 0;
    vector<bool> vis(m * n);
    int idmn = id(m - 1, n - 1);
    while (dq.size()) {
      auto u = dq.front(); dq.pop_front();
      if (u == idmn) return dist[u];
      if (vis[u]) continue;
      vis[u] = true;
      static int d[] = {1, 0, -1, 0, 1};
      int x = u / n, y = u % n;
      for (int k = 0; k < 4; k++) {
        int nx = x + d[k], ny = y + d[k + 1];
        if (0 <= nx && nx < m && 0 <= ny && ny < n) {
          int nid = id(nx, ny), ndis = dist[u] + g[nx][ny];
          if (ndis < dist[nid]) {
            dist[nid] = ndis;
            if (!g[nx][ny]) dq.push_front(nid);
            else dq.push_back(nid);
          }
        }
      }
    }
    return -1;
  }
};
// @lc code=end
