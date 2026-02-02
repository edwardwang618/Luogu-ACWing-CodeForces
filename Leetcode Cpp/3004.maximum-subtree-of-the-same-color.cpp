/*
 * @lc app=leetcode id=3004 lang=cpp
 *
 * [3004] Maximum Subtree of the Same Color
 */

// @lc code=start
class Solution {
public:
  int maximumSubtreeSize(vector<vector<int>> &es, vector<int> &cs) {
    int n = es.size() + 1;
    vector<int> h(n, -1), e(n - 1 << 1), ne(n - 1 << 1);
    int idx = 0;
    auto add = [&](int a, int b) {
      e[idx] = b, ne[idx] = h[a], h[a] = idx++;
    };

    for (auto &e : es) {
      int a = e[0], b = e[1];
      add(a, b), add(b, a);
    };

    int res = 0;
    using PII = pair<int, int>;
    auto dfs = [&](this auto &&dfs, int u, int fa) -> PII {
      int sz = 1;
      bool ok = true;
      for (int i = h[u]; ~i; i = ne[i]) {
        int v = e[i];
        if (v == fa) continue;
        auto [nsz, col] = dfs(v, u);
        if (!~col || cs[u] != col) ok = false;
        else sz += nsz;
      }
      if (ok) res = max(res, sz);
      return ok ? PII{sz, cs[u]} : PII{0, -1};
    };
    dfs(0, -1);
    return res;
  }
};
// @lc code=end
