/*
 * @lc app=leetcode id=3620 lang=cpp
 *
 * [3620] Network Recovery Pathways
 */

// @lc code=start
class Solution {
public:
  using ll = long long;
  int findMaxPathScore(vector<vector<int>> &es, vector<bool> &o, ll k) {
    int n = o.size(), m = es.size();
    vector<int> h(n, -1), e(m), ne(m), w(m);
    int idx = 0;
    auto add = [&](int a, int b, int c) {
      e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
    };
    int l = 0, r = 0;
    for (auto &e : es) {
      add(e[0], e[1], e[2]);
      r = max(r, e[2]);
    }

    static constexpr ll INF = 9e18;
    auto check = [&](int score) {
      vector<ll> f(n, -1);

      auto dfs = [&](this auto &&dfs, int u) -> ll {
        if (~f[u]) return f[u];
        if (u == n - 1) return f[u] = 0;
        ll min_cost = INF;
        for (int i = h[u]; ~i; i = ne[i]) {
          int v = e[i], c = w[i];
          if (o[v] && c >= score)
            min_cost = min(min_cost, c + dfs(v));
        }
        return f[u] = min_cost;
      };

      return dfs(0) <= k;
    };
    while (l < r) {
      int mid = l + r + 1 >> 1;
      if (check(mid)) l = mid;
      else r = mid - 1;
    }
    return check(l) ? l : -1;
  }
};
// @lc code=end
