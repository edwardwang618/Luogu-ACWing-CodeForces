/*
 * @lc app=leetcode id=3372 lang=cpp
 *
 * [3372] Maximize the Number of Target Nodes After Connecting Trees I
 */

// @lc code=start
class Solution {
public:
  vector<int> maxTargetNodes(vector<vector<int>> &es1, vector<vector<int>> &es2,
                             int k) {
    auto solve = [&](auto &es, int max_dist) {
      int n = es.size() + 1;
      vector<int> res(n);
      if (max_dist < 0) return res;
      vector<int> h(n, -1), e(n - 1 << 1), ne(n - 1 << 1);
      int idx = 0;
      auto add = [&](int a, int b) {
        e[idx] = b, ne[idx] = h[a], h[a] = idx++;
      };
      for (auto &e : es) add(e[0], e[1]), add(e[1], e[0]);
      vector<vector<int>> f(n, vector<int>(max_dist + 1));
      auto dfs1 = [&](this auto &&dfs1, int u, int fa) -> void {
        f[u][0] = 1;
        for (int i = h[u]; ~i; i = ne[i]) {
          int v = e[i];
          if (v != fa) {
            dfs1(v, u);
            for (int d = 1; d <= max_dist; d++)
              f[u][d] += f[v][d - 1];
          }
        }
      };
      dfs1(0, -1);
      auto dfs2 = [&](this auto &&dfs2, int u, int fa, auto &from_up) -> void {
        for (int i = 0; i <= max_dist; i++) res[u] += f[u][i] + from_up[i];
        vector<int> next_from_up(max_dist + 1);
        for (int i = h[u]; ~i; i = ne[i]) {
          int v = e[i];
          if (v != fa) {
            for (int d = 1; d <= max_dist; d++)
              next_from_up[d] =
                  f[u][d - 1] - (d >= 2 ? f[v][d - 2] : 0) + from_up[d - 1];
            dfs2(v, u, next_from_up);
          }
        }
      };
      vector<int> from_up(max_dist + 1);
      dfs2(0, -1, from_up);
      return res;
    };
    auto cnt1 = solve(es1, k), cnt2 = solve(es2, k - 1);
    int max_cnt2 = *max_element(cnt2.begin(), cnt2.end());
    for (int &x : cnt1) x += max_cnt2;
    return cnt1;
  }
};
// @lc code=end
