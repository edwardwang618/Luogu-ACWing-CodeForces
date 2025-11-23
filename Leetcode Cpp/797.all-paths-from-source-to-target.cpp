/*
 * @lc app=leetcode id=797 lang=cpp
 *
 * [797] All Paths From Source to Target
 */

// @lc code=start
class Solution {
 public:
  int n;
  vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& g) {
    n = g.size();
    vector<vector<int>> res;
    vector<int> v;
    dfs(0, v, g, res);
    return res;
  }

  void dfs(int u, vector<int>& path, vector<vector<int>>& g,
           vector<vector<int>>& res) {
    path.push_back(u);
    if (u == n - 1) {
      res.push_back(path);
      path.pop_back();
      return;
    }

    for (int i = 0; i < g[u].size(); i++) dfs(g[u][i], path, g, res);
    path.pop_back();
  }
};
// @lc code=end
