/*
 * @lc app=leetcode id=3535 lang=cpp
 *
 * [3535] Unit Conversion II
 */

// @lc code=start
class Solution {
public:
  vector<int> queryConversions(vector<vector<int>> &es,
                               vector<vector<int>> &qs) {
    int n = es.size() + 1;
    vector<int> h(n, -1), e(n - 1), ne(n - 1), w(n - 1);
    int idx = 0;
    auto add = [&](int a, int b, int c) {
      e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
    };
    for (auto &e : es)
      add(e[0], e[1], e[2]);
    vector<int> a(n, -1);
    a[0] = 1;
    static constexpr int MOD = 1e9 + 7;
    using ll = long long;
    auto dfs = [&](this auto &&dfs, int u) -> void {
      for (int i = h[u]; ~i; i = ne[i]) {
        int v = e[i];
        if (!~a[v]) {
          a[v] = (ll)a[u] * w[i] % MOD;
          dfs(v);
        }
      }
    };
    dfs(0);

    vector<int> f(n);
    auto rev = [&](int idx) {
      if (f[idx]) return f[idx];
      int res = 1;
      int x = a[idx], y = MOD - 2;
      while (y) {
        if (y & 1) res = (ll)res * x % MOD;
        y >>= 1;
        x = (ll)x * x % MOD;
      }
      return f[idx] = (int)res;
    };

    vector<int> res;
    res.reserve(qs.size());
    for (auto &q : qs) {
      int x = q[0], y = q[1];
      res.push_back((ll)a[y] * rev(x) % MOD);
    }

    return res;
  }
};
// @lc code=end
