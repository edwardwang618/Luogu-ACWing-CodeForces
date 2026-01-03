/*
 * @lc app=leetcode id=3341 lang=cpp
 *
 * [3341] Find Minimum Time to Reach Last Room I
 */

// @lc code=start
class Solution {
public:
  int minTimeToReach(vector<vector<int>> &g) {
    int m = g.size(), n = g[0].size();
    auto id = [&](int x, int y) {
      return x * n + y;
    };
    int end = id(m - 1, n - 1);
    using PII = pair<int, int>;
    constexpr int INF = 2e9;
    vector<int> dist(m * n, INF);
    dist[0] = 0;
    priority_queue<PII, vector<PII>, greater<>> heap;
    heap.emplace(0, 0);
    while (heap.size()) {
      auto [dis, u] = heap.top(); heap.pop();
      if (dis > dist[u]) continue;
      if (u == end) return dis;
      int x = u / n, y = u % n;
      static int d[] = {1, 0, -1, 0, 1};
      for (int k = 0; k < 4; k++) {
        int nx = x + d[k], ny = y + d[k + 1];
        if (0 <= nx && nx < m && 0 <= ny && ny < n) {
          int ndis = max(g[nx][ny] + 1, dis + 1), nxy = id(nx, ny);
          if (ndis < dist[nxy]) {
            dist[nxy] = ndis;
            heap.emplace(ndis, nxy);
          }
        }
      }
    }
    return -1;
  }
};
// @lc code=end
