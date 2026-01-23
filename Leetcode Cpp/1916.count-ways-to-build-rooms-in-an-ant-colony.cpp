/*
 * @lc app=leetcode id=1916 lang=cpp
 *
 * [1916] Count Ways to Build Rooms in an Ant Colony
 */

// @lc code=start
class Solution {
public:
  int waysToBuildRooms(vector<int> &p) {
    int n = p.size();
    vector<int> h(n, -1), e(n - 1), ne(n - 1);
    int idx = 0;
    auto add = [&](int a, int b) { e[idx] = b, ne[idx] = h[a], h[a] = idx++; };
    for (int i = 1; i < n; i++) add(p[i], i);
    vector<int> sz(n);
    auto dfs = [&](this auto &&dfs, int u) -> int {
      sz[u] = 1;
      for (int i = h[u]; ~i; i = ne[i])
        sz[u] += dfs(e[i]);
      return sz[u];
    };

    dfs(0);
    
    using ll = long long;
    static constexpr ll MOD = 1e9 + 7;
    auto pow = [&](ll a, ll b) {
      ll res = 1;
      while (b) {
        if (b & 1) res = res * a % MOD;
        b >>= 1ll;
        a = a * a % MOD;
      }
      return res;
    };
    ll res = 1;
    for (int i = 2; i <= n; i++) res = res * i % MOD;
    for (int i = 0; i < n; i++) res = res * pow(sz[i], MOD - 2) % MOD;

    return res;
  }
};
// @lc code=end
