/*
 * @lc app=leetcode id=2368 lang=cpp
 *
 * [2368] Reachable Nodes With Restrictions
 */

// @lc code=start
class Solution {
public:
  int reachableNodes(int n, vector<vector<int>> &es, vector<int> &r) {
    int m = n - 1;
    vector<int> h(n, -1), e(m << 1), ne(m << 1);
    int idx = 0;
    auto add = [&](int a, int b) {
      e[idx] = b, ne[idx] = h[a], h[a] = idx++;
    };
    for (auto &e : es) {
      int a = e[0], b = e[1];
      add(a, b), add(b, a);
    }

    vector<bool> used(n);
    for (int x : r) used[x] = true;
    auto dfs = [&](this auto &&dfs, int u, int from) -> int {
      if (used[u]) return 0;
      int res = 1;
      for (int i = h[u]; ~i; i = ne[i]) {
        int v = e[i];
        if (v == from) continue;
        res += dfs(v, u);
      }
      return res;
    };
    return dfs(0, -1);
  }
};
// @lc code=end
