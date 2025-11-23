/*
 * @lc app=leetcode id=2065 lang=cpp
 *
 * [2065] Maximum Path Quality of a Graph
 */

// @lc code=start
class Solution {
 public:
  int res;
  int maximalPathQuality(vector<int>& vs, vector<vector<int>>& es,
                         int maxTime) {
    int n = vs.size();
    vector<vector<pair<int, int>>> g(n);
    for (auto& e : es) {
      g[e[0]].push_back({e[1], e[2]});
      g[e[1]].push_back({e[0], e[2]});
    }

    vector<int> vis(n);
    dfs(0, 0, 0, maxTime, g, vs, vis);
    return res;
  }

  void dfs(int u, int score, int time, int maxTime,
           vector<vector<pair<int, int>>>& g, vector<int>& vs,
           vector<int>& vis) {
    if (time > maxTime) return;
    if (!vis[u]) score += vs[u];
    vis[u]++;
    if (!u) res = max(res, score);

    for (auto& p : g[u])
      dfs(p.first, score, time + p.second, maxTime, g, vs, vis);
    vis[u]--;
  }
};
// @lc code=end
