/*
 * @lc app=leetcode id=743 lang=cpp
 *
 * [743] Network Delay Time
 */

// @lc code=start
class Solution {
 public:
  int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    int g[n + 1][n + 1];
    memset(g, 0x3f, sizeof g);
    for (int i = 1; i <= n; i++) g[i][i] = 0;
    for (auto& t : times) g[t[0]][t[1]] = min(g[t[0]][t[1]], t[2]);
    int dist[n + 1];
    memset(dist, 0x3f, sizeof dist);
    bool vis[n + 1];
    memset(vis, 0, sizeof vis);
    dist[k] = 0;
    for (int i = 1; i <= n; i++) {
      int t = -1;
      for (int v = 1; v <= n; v++)
        if (!vis[v] && (t == -1 || dist[v] < dist[t])) t = v;
      if (dist[t] == 0x3f3f3f3f) return -1;
      vis[t] = true;
      for (int v = 1; v <= n; v++)
        if (!vis[v] && dist[v] > dist[t] + g[t][v]) dist[v] = dist[t] + g[t][v];
    }

    return *max_element(dist + 1, dist + n + 1);
  }
};
// @lc code=end
