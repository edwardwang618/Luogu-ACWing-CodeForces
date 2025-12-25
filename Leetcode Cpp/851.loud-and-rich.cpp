/*
 * @lc app=leetcode id=851 lang=cpp
 *
 * [851] Loud and Rich
 */

// @lc code=start
class Solution {
public:
  vector<int> loudAndRich(vector<vector<int>> &es, vector<int> &q) {
    int n = q.size(), m = es.size();
    vector<int> h(n, -1), e(m), ne(m);
    int idx = 0;
    auto add = [&](int a, int b) { e[idx] = b, ne[idx] = h[a], h[a] = idx++; };
    for (auto &e : es)
      add(e[1], e[0]);

    vector<int> res(n, -1);
    auto dfs = [&](this auto &&dfs, int u) -> void {
      if (~res[u])
        return;
      res[u] = u;
      for (int i = h[u]; ~i; i = ne[i]) {
        int v = e[i];
        dfs(v);
        if (q[res[u]] > q[res[v]])
          res[u] = res[v];
      }
    };
    for (int i = 0; i < n; i++)
      dfs(i);
    return res;
  }
};
// @lc code=end
