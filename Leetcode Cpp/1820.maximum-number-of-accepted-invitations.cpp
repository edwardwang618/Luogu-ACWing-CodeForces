/*
 * @lc app=leetcode id=1820 lang=cpp
 *
 * [1820] Maximum Number of Accepted Invitations
 */

// @lc code=start
class Solution {
public:
  int maximumInvitations(vector<vector<int>> &g) {
    int m = g.size(), n = g[0].size();
    int res = 0;
    vector<bool> vis(n);
    vector<int> match(n, -1);
    auto dfs = [&](this auto &&dfs, int u) -> bool {
      for (int v = 0; v < n; v++) {
        if (g[u][v] && !vis[v]) {
          vis[v] = true;
          if (!~match[v] || dfs(match[v])) {
            match[v] = u;
            return true;
          }
        }
      }
      return false;
    };
    for (int i = 0; i < m; i++) {
      fill(vis.begin(), vis.end(), false);
      if (dfs(i)) res++;
    }
    return res;
  }
};
// @lc code=end
