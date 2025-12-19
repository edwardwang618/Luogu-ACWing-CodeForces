/*
 * @lc app=leetcode id=1786 lang=cpp
 *
 * [1786] Number of Restricted Paths From First to Last Node
 */

// @lc code=start
class Solution {
public:
  using PII = pair<int, int>;
  int countRestrictedPaths(int n, vector<vector<int>> &es) {
    static constexpr int INF = 2e9, MOD = 1e9 + 7;
    int m = es.size();
    vector<int> h(n + 1, -1), e(m << 1), ne(m << 1), w(m << 1);
    int idx = 0;
    auto add = [&](int a, int b, int c) {
      e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
    };
    for (auto &e : es) {
      int a = e[0], b = e[1], c = e[2];
      add(a, b, c);
      add(b, a, c);
    }

    vector<int> dist(n + 1, INF);
    dist[n] = 0;
    vector<bool> vis(n + 1);
    priority_queue<PII, vector<PII>, greater<>> heap;
    heap.push({0, n});
    while (heap.size()) {
      auto [d, u] = heap.top(); heap.pop();
      if (vis[u]) continue;
      vis[u] = true;
      for (int i = h[u]; ~i; i = ne[i]) {
        int v = e[i];
        if (dist[v] > d + w[i]) {
          dist[v] = d + w[i];
          heap.push({dist[v], v});
        }
      }
    }

    vector<int> f(n + 1, -1);
    auto dfs = [&](auto&& self, int u) -> int {
      if (~f[u]) return f[u];
      if (u == n) return f[u] = 1;
      f[u] = 0;
      for (int i = h[u]; ~i; i = ne[i]) {
        int v = e[i];
        if (dist[v] < dist[u]) f[u] = (f[u] + self(self, v)) % MOD;
      }
      return f[u];
    };
    return dfs(dfs, 1);
  }
};
// @lc code=end
