/*
 * @lc app=leetcode id=1443 lang=cpp
 *
 * [1443] Minimum Time to Collect All Apples in a Tree
 */

// @lc code=start
class Solution {
public:
  int minTime(int n, vector<vector<int>> &es, vector<bool> &has) {
    vector<int> h(n, -1), e(n << 1), ne(n << 1);
    int idx = 0;
    auto add = [&](int a, int b) {
      e[idx] = b, ne[idx] = h[a], h[a] = idx++;
    };
    for (auto &e : es) {
      int a = e[0], b = e[1];
      add(a, b), add(b, a);
    }

    auto dfs = [&](this auto &&dfs, int u, int pa) -> int {
      int res = 0;
      bool has_apple = has[u];
      for (int i = h[u]; ~i; i = ne[i]) {
        int v = e[i];
        if (v == pa) continue;
        int t = dfs(v, u);
        if (t || has[v]) res += t + 2;
      }
      return res;
    };
    return dfs(0, -1);
  }
};
// @lc code=end
