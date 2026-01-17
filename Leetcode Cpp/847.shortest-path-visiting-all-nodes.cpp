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
    if (n == 1) return 0;
    const int FULL = (1 << n) - 1;
    queue<PII> q;
    vector vis(n, vector<bool>((1 << n) - 1));
    for (int i = 0; i < n; i++) {
      int s = 1 << i;
      vis[i][s] = true;
      q.emplace(i, s);
    }

    for (int dis = 1; q.size(); dis++) {
      for (int _ = q.size(); _--; ) {
        auto [u, s] = q.front(); q.pop();
        for (int v : g[u]) {
          int ns = s | (1 << v);
          if (ns == FULL) return dis;
          if (vis[v][ns]) continue;
          vis[v][ns] = true;
          q.emplace(v, ns);
        }
      }
    }
    return -1;
  }
};
// @lc code=end
