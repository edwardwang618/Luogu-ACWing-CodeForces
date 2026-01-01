/*
 * @lc app=leetcode id=2101 lang=cpp
 *
 * [2101] Detonate the Maximum Bombs
 */

// @lc code=start
class Solution {
public:
  int maximumDetonation(vector<vector<int>> &bs) {
    int n = bs.size();
    vector<int> h(n, -1), e(n * (n - 1)), ne(n * (n - 1));
    int idx = 0;
    auto add = [&](int a, int b) { e[idx] = b, ne[idx] = h[a], h[a] = idx++; };
    using ll = long long;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++) {
        if (i == j)
          continue;
        ll dx = abs(bs[i][0] - bs[j][0]), dy = abs(bs[i][1] - bs[j][1]);
        ll r = bs[i][2];
        if (dx * dx + dy * dy <= r * r) add(i, j);
      }
    vector<bool> vis(n);
    auto dfs = [&](this auto &&dfs, int u) -> int {
      vis[u] = true;
      int res = 1;
      for (int i = h[u]; ~i; i = ne[i]) {
        int v = e[i];
        if (!vis[v]) res += dfs(v);
      }
      return res;
    };
    int res = 0;
    for (int i = 0; i < n; i++) {
      fill(vis.begin(), vis.end(), false); 
      res = max(res, dfs(i));
    }
    return res;
  }
};
// @lc code=end
