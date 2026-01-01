/*
 * @lc app=leetcode id=2477 lang=cpp
 *
 * [2477] Minimum Fuel Cost to Report to the Capital
 */

// @lc code=start
class Solution {
public:
  using ll = long long;
  ll minimumFuelCost(vector<vector<int>> &es, int seats) {
    int n = es.size() + 1, m = n - 1;
    vector<int> h(n, -1), e(m << 1), ne(m << 1);
    int idx = 0;
    auto add = [&](int a, int b) {
      e[idx] = b, ne[idx] = h[a], h[a] = idx++;
    };
    for (auto &e : es) {
      int a = e[0], b = e[1];
      add(a, b), add(b, a);
    }

    ll res = 0;
    auto dfs = [&](this auto &&dfs, int u, int from) -> int {
      ll cnt = 1;
      for (int i = h[u]; ~i; i = ne[i]) {
        int v = e[i];
        if (v == from) continue;
        cnt += dfs(v, u);
      }
      if (u) res += (cnt + seats - 1) / seats;
      return cnt;
    };
    dfs(0, -1);
    return res;
  }
};
// @lc code=end
