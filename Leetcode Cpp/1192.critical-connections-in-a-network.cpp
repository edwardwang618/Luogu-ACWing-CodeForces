/*
 * @lc app=leetcode id=1192 lang=cpp
 *
 * [1192] Critical Connections in a Network
 */

// @lc code=start
class Solution {
public:
  vector<vector<int>> criticalConnections(int n, vector<vector<int>> &es) {
    int m = es.size();
    vector<int> h(n, -1), e(m << 1), ne(m << 1);
    int idx = 0;
    auto add = [&](int a, int b) {
      e[idx] = b, ne[idx] = h[a], h[a] = idx++;
    };
    for (auto e : es) {
      int a = e[0], b = e[1];
      add(a, b), add(b, a);
    }
    vector<int> dfn(n), low(n);
    int timestamp = 0;

    vector<vector<int>> res;
    auto dfs = [&](auto &&self, int u, int from, int timestamp) -> void {
      dfn[u] = low[u] = ++timestamp;
      for (int i = h[u]; ~i; i = ne[i]) {
        int v = e[i];
        if (!dfn[v]) {
          self(self, v, u, timestamp);
          low[u] = min(low[u], low[v]);
          if (dfn[u] < low[v]) res.push_back({u, v});
        } else if (v != from) low[u] = min(low[u], low[v]);
      }
    };
    dfs(dfs, 0, -1, 0);
    return res;
  }
};
// @lc code=end
