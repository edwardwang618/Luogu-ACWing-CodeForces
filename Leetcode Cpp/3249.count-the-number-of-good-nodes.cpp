/*
 * @lc app=leetcode id=3249 lang=cpp
 *
 * [3249] Count the Number of Good Nodes
 */

// @lc code=start
class Solution {
public:
  int countGoodNodes(vector<vector<int>> &es) {
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

    int res = 0;
    auto dfs = [&](this auto &&dfs, int u, int fa) -> int {
      int sz = 1, asz = -1;
      bool ok = true;
      for (int i = h[u]; ~i; i = ne[i]) {
        int v = e[i];
        if (v == fa) continue;
        int csz = dfs(v, u);
        if (!~asz) asz = csz;
        else if (csz != asz) ok = false;
        sz += csz;
      }
      if (ok) res++;
      return sz;
    };
    dfs(0, -1);
    return res;
  }
};
// @lc code=end
