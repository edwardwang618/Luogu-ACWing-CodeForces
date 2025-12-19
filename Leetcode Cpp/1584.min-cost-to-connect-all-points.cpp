/*
 * @lc app=leetcode id=1584 lang=cpp
 *
 * [1584] Min Cost to Connect All Points
 */

// @lc code=start
class Solution {
public:
  int minCostConnectPoints(vector<vector<int>> &ps) {
    int n = ps.size();
    int g[n][n];
    memset(g, -1, sizeof g);
    for (int i = 0; i < n; i++) g[i][i] = 0;
    auto d = [&](int i, int j) {
      static auto dist = [](auto& x, auto& y) {
        return abs(x[0] - y[0]) + abs(x[1] - y[1]);
      };
      return ~g[i][j] ? g[i][j] : g[i][j] = dist(ps[i], ps[j]);
    };

    int dist[n];
    memset(dist, 0x3f, sizeof dist);
    bool vis[n];
    memset(vis, 0, sizeof vis);

    int res = 0;
    for (int i = 1; i <= n; i++) {
      int u = -1;
      for (int v = 0; v < n; v++)
        if (!vis[v] && (!~u || dist[u] > dist[v])) u = v;
      if (u) res += dist[u];
      vis[u] = true;
      for (int v = 0; v < n; v++)
        dist[v] = min(dist[v], d(u, v));
    }

    return res;
  }
};
// @lc code=end
