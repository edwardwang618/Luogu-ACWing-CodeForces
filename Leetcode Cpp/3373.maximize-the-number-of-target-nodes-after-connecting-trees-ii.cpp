/*
 * @lc app=leetcode id=3373 lang=cpp
 *
 * [3373] Maximize the Number of Target Nodes After Connecting Trees II
 */

// @lc code=start
class Solution {
public:
  vector<int> maxTargetNodes(vector<vector<int>> &es1,
                             vector<vector<int>> &es2) {
    auto solve = [&](auto &es) {
      int n = es.size() + 1;
      vector<int> h(n, -1), e(n - 1 << 1), ne(n - 1 << 1);
      int idx = 0;
      auto add = [&](int a, int b) {
        e[idx] = b, ne[idx] = h[a], h[a] = idx++;
      };
      for (auto &e : es) {
        int a = e[0], b = e[1];
        add(a, b), add(b, a);
      }

      vector<bool> parity(n);
      auto dfs = [&](this auto &&dfs, int u, int fa, int d) -> void {
        parity[u] = d & 1;
        for (int i = h[u]; ~i; i = ne[i]) {
          int v = e[i];
          if (v != fa)
            dfs(v, u, d + 1);
        }
      };
      dfs(0, -1, 0);

      int cnt[2] = {0, 0};
      for (int i = 0; i < n; i++)
        cnt[parity[i]]++;

      vector<int> res(n);
      for (int i = 0; i < n; i++)
        res[i] = parity[i] ? cnt[1] : cnt[0];

      return make_pair(res, max(cnt[0], cnt[1]));
    };

    auto [c1, _] = solve(es1);
    auto [_, max2] = solve(es2);

    int n = es1.size() + 1;
    vector<int> res(n);
    for (int i = 0; i < n; i++)
      res[i] = c1[i] + max2;

    return res;
  }
};
// @lc code=end
