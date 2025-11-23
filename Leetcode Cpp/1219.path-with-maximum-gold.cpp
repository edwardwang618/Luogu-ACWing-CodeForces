/*
 * @lc app=leetcode id=1219 lang=cpp
 *
 * [1219] Path with Maximum Gold
 */

// @lc code=start
class Solution {
 public:
  int getMaximumGold(vector<vector<int>>& g) {
    int res = 0, m = g.size(), n = g[0].size();
    vector<vector<bool>> vis(m, vector<bool>(n));
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        if (g[i][j]) {
          res = max(res, dfs(i, j, g, vis));
        }

    return res;
  }

  int dfs(int x, int y, vector<vector<int>>& g, vector<vector<bool>>& vis) {
    vis[x][y] = true;
    int res = g[x][y];
    static int d[] = {-1, 0, 1, 0, -1};
    for (int _ = 0; _ < 4; _++) {
      int nx = x + d[_], ny = y + d[_ + 1];
      if (0 <= nx && nx < g.size() && 0 <= ny && ny < g[0].size() &&
          g[nx][ny] && !vis[nx][ny])
        res = max(res, g[x][y] + dfs(nx, ny, g, vis));
    }

    vis[x][y] = false;
    return res;
  }
};
// @lc code=end
