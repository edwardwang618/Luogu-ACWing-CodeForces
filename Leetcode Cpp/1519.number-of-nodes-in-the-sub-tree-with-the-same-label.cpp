/*
 * @lc app=leetcode id=1519 lang=cpp
 *
 * [1519] Number of Nodes in the Sub-Tree With the Same Label
 */

// @lc code=start
class Solution {
public:
  vector<int> countSubTrees(int n, vector<vector<int>> &es, string &ls) {
    vector<int> h(n, -1), e(n - 1 << 1), ne(n - 1 << 1);
    int idx = 0;
    auto add = [&](int a, int b) { e[idx] = b, ne[idx] = h[a], h[a] = idx++; };
    for (auto &e : es) {
      int a = e[0], b = e[1];
      add(a, b), add(b, a);
    }

    vector<int> res(n);
    auto dfs = [&](this auto &&dfs, int u, int from) -> vector<int> {
      vector<int> cnt(26);
      for (int i = h[u]; ~i; i = ne[i]) {
        int v = e[i];
        if (v != from) {
          auto c = dfs(v, u);
          for (int i = 0; i < 26; i++)
            cnt[i] += c[i];
        }
      }

      res[u] = ++cnt[ls[u] - 'a'];
      return cnt;
    };
    dfs(0, -1);
    return res;
  }
};
// @lc code=end
