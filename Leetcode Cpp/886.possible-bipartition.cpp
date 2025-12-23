/*
 * @lc app=leetcode id=886 lang=cpp
 *
 * [886] Possible Bipartition
 */

// @lc code=start
class Solution {
public:
  bool possibleBipartition(int n, vector<vector<int>> &es) {
    int m = es.size();
    vector<int> h(n + 1, -1), e(m << 1), ne(m << 1);
    int idx;
    auto add = [&](int a, int b) {
      e[idx] = b, ne[idx] = h[a], h[a] = idx++;
    };
    for (auto &e : es) {
      int a = e[0], b = e[1];
      add(a, b), add(b, a);
    }

    vector<int> col(n + 1, -1);

    auto dfs = [&](auto &&self, int u, int c) -> bool {
      col[u] = c;
      for (int i = h[u]; ~i; i = ne[i]) {
        int v = e[i];
        if (~col[v] && c == col[v]) return false;
        if (!~col[v] && !self(self, v, !c)) return false;
      }
      return true;
    };

    for (int i = 1; i <= n; i++)
      if (!~col[i] && !dfs(dfs, i, 0)) return false;
    return true;
  }
};
// @lc code=end
