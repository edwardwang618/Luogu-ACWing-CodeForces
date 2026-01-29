/*
 * @lc app=leetcode id=2646 lang=cpp
 *
 * [2646] Minimize the Total Price of the Trips
 */

// @lc code=start
class Solution {
public:
  int minimumTotalPrice(int n, vector<vector<int>> &es, vector<int> &ps,
                        vector<vector<int>> &ts) {
    vector<int> h(n, -1), e(n - 1 << 1), ne(n - 1 << 1);
    int idx = 0;
    auto add = [&](int a, int b) { e[idx] = b, ne[idx] = h[a], h[a] = idx++; };
    for (auto &e : es) {
      int a = e[0], b = e[1];
      add(a, b), add(b, a);
    }
    vector<int> cnt(n);
    auto dfs_cnt = [&](this auto &&dfs_cnt, int u, int from, int end) -> bool {
      if (u == end) {
        cnt[u]++;
        return true;
      }

      for (int i = h[u]; ~i; i = ne[i]) {
        int v = e[i];
        if (v != from && dfs_cnt(v, u, end)) {
          cnt[u]++;
          return true;
        }
      }
      return false;
    };
    for (auto &t : ts)
      dfs_cnt(t[0], -1, t[1]);

    auto dfs = [&](this auto &&dfs, int u, int from) -> pair<int, int> {
      int non_half = ps[u] * cnt[u], half = non_half / 2;
      for (int i = h[u]; ~i; i = ne[i]) {
        int v = e[i];
        if (v != from) {
          auto [nh, h] = dfs(v, u);
          non_half += min(nh, h);
          half += nh;
        }
      }
      return {non_half, half};
    };
    auto [non_half, half] = dfs(0, -1);
    return min(non_half, half);
  }
};
// @lc code=end
