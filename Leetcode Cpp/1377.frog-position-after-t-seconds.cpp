/*
 * @lc app=leetcode id=1377 lang=cpp
 *
 * [1377] Frog Position After T Seconds
 */

// @lc code=start
class Solution {
public:
  double frogPosition(int n, vector<vector<int>> &es, int t, int target) {
    vector<vector<int>> g(n + 1);
    for (auto &e : es) {
      g[e[0]].push_back(e[1]);
      g[e[1]].push_back(e[0]);
    }
    return dfs(1, -1, t, 1.0, g, target);
  }

  static double dfs(int u, int from, int t, double p, auto &g, int target) {
    if (!t)
      return u == target ? p : 0;

    int cnt = g[u].size();
    if (u != 1)
      cnt--;

    if (!cnt)
      return u == target ? p : 0;

    for (int v : g[u]) {
      if (v == from)
        continue;
      if (double res = dfs(v, u, t - 1, p / cnt, g, target); res > 0)
        return res;
    }

    return 0;
  }
};
// @lc code=end
