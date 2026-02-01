/*
 * @lc app=leetcode id=2277 lang=cpp
 *
 * [2277] Closest Node to Path in Tree
 */

// @lc code=start
class Solution {
public:
  vector<int> closestNode(int n, vector<vector<int>> &es,
                          vector<vector<int>> &qs) {
    int m = es.size();
    vector<int> h(n, -1), e(m << 1), ne(m << 1);
    int idx = 0;
    auto add = [&](int a, int b) { e[idx] = b, ne[idx] = h[a], h[a] = idx++; };
    for (auto &e : es) {
      int a = e[0], b = e[1];
      add(a, b), add(b, a);
    }

    const int LOG = n == 1 ? 1 : (int)log2(n - 1) + 1;
    vector<int> dep(n);
    vector<vector<int>> f(LOG, vector<int>(n, -1));
    auto dfs = [&](this auto &&dfs, int u, int fa, int d) -> void {
      dep[u] = d;
      f[0][u] = fa;
      for (int i = 1; i < LOG && ~f[i - 1][u]; i++)
        f[i][u] = f[i - 1][f[i - 1][u]];
      for (int i = h[u]; ~i; i = ne[i]) {
        int v = e[i];
        if (v != fa)
          dfs(v, u, d + 1);
      }
    };
    dfs(0, -1, 0);
    vector<vector<int>> lca_v(n, vector<int>(n, -1));
    auto lca = [&](int u, int v) {
      if (~lca_v[u][v])
        return lca_v[u][v];
      if (dep[u] > dep[v])
        swap(u, v);
      int diff = dep[v] - dep[u];
      for (int i = 0; (1 << i) <= diff; i++)
        if (diff >> i & 1)
          v = f[i][v];
      if (u == v)
        return u;
      for (int i = LOG - 1; i >= 0; i--)
        if (f[i][u] != f[i][v])
          u = f[i][u], v = f[i][v];
      return lca_v[u][v] = lca_v[v][u] = f[0][u];
    };

    vector<int> res;
    res.reserve(qs.size());
    for (auto &q : qs) {
      int st = q[0], ed = q[1], node = q[2];
      int c = lca(st, ed), c2 = lca(st, node), c3 = lca(ed, node);
      if (dep[c2] > dep[c])
        c = c2;
      if (dep[c3] > dep[c])
        c = c3;
      res.push_back(c);
    }
    return res;
  }
};
// @lc code=end
