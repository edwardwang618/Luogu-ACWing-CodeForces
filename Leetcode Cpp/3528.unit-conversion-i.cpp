/*
 * @lc app=leetcode id=3528 lang=cpp
 *
 * [3528] Unit Conversion I
 */

// @lc code=start
class Solution {
public:
  vector<int> baseUnitConversions(vector<vector<int>> &es) {
    int n = es.size() + 1;
    vector<int> h(n, -1), e(n - 1), ne(n - 1), w(n - 1);
    int idx = 0;
    auto add = [&](int a, int b, int c) {
      e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
    };
    for (auto &e : es) add(e[0], e[1], e[2]);
    vector<int> res(n, -1);
    res[0] = 1;
    static constexpr int MOD = 1e9 + 7;
    using ll = long long;
    auto dfs = [&](this auto &&dfs, int u) -> void {
      for (int i = h[u]; ~i; i = ne[i]) {
        int v = e[i];
        if (!~res[v]) {
          res[v] = (ll)res[u] * w[i] % MOD;
          dfs(v);
        }
      }
    };
    dfs(0);
    return res;
  }
};
// @lc code=end
