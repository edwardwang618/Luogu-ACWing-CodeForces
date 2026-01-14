/*
 * @lc app=leetcode id=1466 lang=cpp
 *
 * [1466] Reorder Routes to Make All Paths Lead to the City Zero
 */

// @lc code=start
class Solution {
public:
  int minReorder(int n, vector<vector<int>> &es) {
    int m = es.size();
    vector<int> h(n, -1), e(m << 1), ne(m << 1), w(m << 1);
    int idx = 0;
    auto add = [&](int a, int b, int c) {
      e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
    };
    for (auto &e : es) {
      int a = e[0], b = e[1];
      add(b, a, 0), add(a, b, 1);
    };

    auto dfs = [&](this auto &&dfs, int u, int from) -> int {
      int cnt = 0;
      for (int i = h[u]; ~i; i = ne[i]) {
        int v = e[i];
        if (v == from) continue;
        cnt += w[i] + dfs(v, u);
      }
      return cnt;
    };
    return dfs(0, -1);
  }
};
// @lc code=end
