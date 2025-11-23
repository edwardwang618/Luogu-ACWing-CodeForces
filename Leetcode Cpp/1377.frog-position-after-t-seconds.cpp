/*
 * @lc app=leetcode id=1377 lang=cpp
 *
 * [1377] Frog Position After T Seconds
 */

// @lc code=start
class Solution {
 public:
  double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
    unordered_map<int, vector<int>> g;
    for (auto& e : edges) {
      g[e[0]].push_back(e[1]);
      g[e[1]].push_back(e[0]);
    }
    return dfs(1, -1, t, 1.0, g, target);
  }

  double dfs(int u, int from, int t, double p,
             unordered_map<int, vector<int>>& g, int target) {
    if (!t) {
      if (u == target) return p;
      return 0;
    }

    int cnt = g[u].size();
    if (u != 1) cnt--;

    if (!cnt) {
      if (u == target) return p;
      return 0;
    }

    double res = 0;
    for (int v : g[u]) {
      if (v == from) continue;
      if ((res = dfs(v, u, t - 1, p / cnt, g, target)) > 0) return res;
    }

    return 0;
  }
};
// @lc code=end
