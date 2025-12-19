/*
 * @lc app=leetcode id=847 lang=cpp
 *
 * [847] Shortest Path Visiting All Nodes
 */

// @lc code=start
class Solution {
public:
  using PII = pair<int, int>;
  int shortestPathLength(vector<vector<int>> &g) {
    int n = g.size();
    const int FULL = (1 << n) - 1, INF = 2e9;
    vector<vector<int>> dist(n, vector<int>(1 << n, INF));
    queue<PII> q;
    for (int i = 0; i < n; i++) {
      int s = 1 << i;
      dist[i][s] = 0;
      q.emplace(i, s);
    }

    while (q.size()) {
      auto [u, s] = q.front(); q.pop();
      int d = dist[u][s];
      if (s == FULL) return d;
      for (int v : g[u]) {
        int ns = s | (1 << v);
        if (dist[v][ns] > d + 1) {
          dist[v][ns] = d + 1;
          q.emplace(v, ns);
        }
      }
    }
    return -1;
  }
};
// @lc code=end
