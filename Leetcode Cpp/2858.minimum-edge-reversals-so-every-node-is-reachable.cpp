/*
 * @lc app=leetcode id=2858 lang=cpp
 *
 * [2858] Minimum Edge Reversals So Every Node Is Reachable
 */

// @lc code=start
class Solution {
public:
  vector<int> minEdgeReversals(int n, vector<vector<int>> &es) {
    int m = n - 1;
    vector<int> h(n, -1), e(m << 1), ne(m << 1);
    vector<bool> w(m << 1);
    int idx = 0;
    auto add = [&](int a, int b, bool c) {
      e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
    };
    for (auto &e : es) {
      int a = e[0], b = e[1];
      add(a, b, true), add(b, a, false);
    }

    vector<int> res(n);
    auto dfs1 = [&](this auto &&dfs1, int u, int from) -> void {
      for (int i = h[u]; ~i; i = ne[i]) {
        int v = e[i];
        if (v == from) continue;
        res[0] += w[i] ? 0 : 1;
        dfs1(v, u);
      }
    };
    dfs1(0, -1);

    auto dfs2 = [&](this auto &&dfs2, int u, int from) -> void {
      for (int i = h[u]; ~i; i = ne[i]) {
        int v = e[i], c = w[i];
        if (v == from) continue;
        res[v] = res[u] + (w[i] ? 1 : -1);
        dfs2(v, u);
      }
    };
    dfs2(0, -1);
    return res;
  }
};
// @lc code=end
