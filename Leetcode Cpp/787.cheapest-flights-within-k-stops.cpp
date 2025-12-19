/*
 * @lc app=leetcode id=787 lang=cpp
 *
 * [787] Cheapest Flights Within K Stops
 */

// @lc code=start
class Solution {
public:
  int findCheapestPrice(int n, vector<vector<int>> &fs, int sc, int dt, int k) {
    static constexpr int INF = 0x3f3f3f3f;
    vector<vector<int>> dist(2, vector<int>(n, INF));
    dist[0][sc] = dist[1][sc] = 0;
    for (int i = 1; i <= k + 1; i++)
      for (auto &e : fs) {
        int u = e[0], v = e[1], w = e[2];
        dist[i & 1][v] = min(dist[i & 1][v], dist[i - 1 & 1][u] + w);
      }

    return dist[k + 1 & 1][dt] == INF ? -1 : dist[k + 1 & 1][dt];
  }
};
// @lc code=end
