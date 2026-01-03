/*
 * @lc app=leetcode id=2577 lang=cpp
 *
 * [2577] Minimum Time to Visit a Cell In a Grid
 */

// @lc code=start
class Solution {
public:
  int minimumTime(vector<vector<int>> &g) {
    if (g[1][0] > 1 && g[0][1] > 1) return -1;
    int m = g.size(), n = g[0].size();
    auto id = [&](int x, int y) {
      return x * n + y;
    };
    constexpr int INF = 2e9;
    vector<int> dist(m * n, INF);
    using PII = pair<int, int>;
    priority_queue<PII, vector<PII>, greater<>> heap;
    dist[0] = 0;
    heap.emplace(0, 0);
    int idmn = id(m - 1, n - 1);
    while (heap.size()) {
      auto [dis, u] = heap.top(); heap.pop();
      if (u == idmn) return dis;
      if (dis > dist[u]) continue;
      static int d[] = {1, 0, -1, 0, 1};
      int x = u / n, y = u % n;
      for (int k = 0; k < 4; k++) {
        int nx = x + d[k], ny = y + d[k + 1];
        if (0 <= nx && nx < m && 0 <= ny && ny < n) {
          int nid = id(nx, ny);
          int ndis;
          if (g[nx][ny] <= dis + 1) ndis = dis + 1;
          else {
            ndis = g[nx][ny];
            if ((g[nx][ny] - dis) % 2 == 0) ndis++;
          }
          if (ndis < dist[nid]) {
            dist[nid] = ndis;
            heap.emplace(ndis, nid);
          }
        }
      }
    }
    return -1;
  }
};
// @lc code=end
