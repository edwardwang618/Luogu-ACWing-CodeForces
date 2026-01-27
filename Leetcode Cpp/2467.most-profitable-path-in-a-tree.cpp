/*
 * @lc app=leetcode id=2467 lang=cpp
 *
 * [2467] Most Profitable Path in a Tree
 */

// @lc code=start
class Solution {
public:
  int mostProfitablePath(vector<vector<int>> &es, int bob, vector<int> &a) {
    int n = es.size() + 1;
    vector<int> h(n, -1), e(n - 1 << 1), ne(n - 1 << 1);
    int idx = 0;
    auto add = [&](int a, int b) { e[idx] = b, ne[idx] = h[a], h[a] = idx++; };
    for (auto &e : es) {
      int a = e[0], b = e[1];
      add(a, b), add(b, a);
    }
    vector<int> path;
    auto dfs1 = [&](this auto &&dfs1, int u, int from) -> bool {
      path.push_back(u);
      if (!u) return true;
      for (int i = h[u]; ~i; i = ne[i]) {
        int v = e[i];
        if (v != from && dfs1(v, u)) return true;
      }
      path.pop_back();
      return false;
    };
    dfs1(bob, -1);
    vector<int> time(n, -1);
    for (int i = 0; i < path.size(); i++) time[path[i]] = i;

    int res = -2e9;
    auto dfs2 = [&](this auto &&dfs2, int u, int from, int t, int rew) -> void {
      if (t < time[u] || !~time[u]) rew += a[u];
      else if (t == time[u]) rew += a[u] / 2;

      bool is_leaf = true;
      for (int i = h[u]; ~i; i = ne[i]) {
        int v = e[i];
        if (v != from) {
          is_leaf = false;
          dfs2(v, u, t + 1, rew);
        }
      }
      if (is_leaf) res = max(res, rew);
    };
    dfs2(0, -1, 0, 0);
    return res;
  }
};
// @lc code=end
