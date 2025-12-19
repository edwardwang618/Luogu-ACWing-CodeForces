/*
 * @lc app=leetcode id=417 lang=cpp
 *
 * [417] Pacific Atlantic Water Flow
 */

// @lc code=start
class Solution {
public:
  vector<vector<int>> pacificAtlantic(vector<vector<int>> &hs) {
    int m = hs.size(), n = hs[0].size();
    vector<vector<bool>> vis(m, vector<bool>(n));
    vector<vector<int>> can_flow(m, vector<int>(n));
    auto dfs = [&](auto &&self, int x, int y, auto &vis) -> void {
      static int d[] = {1, 0, -1, 0, 1};
      vis[x][y] = true;
      can_flow[x][y]++;
      for (int k = 0; k < 4; k++) {
        int nx = x + d[k], ny = y + d[k + 1];
        if (0 <= nx && nx < m && 0 <= ny && ny < n && !vis[nx][ny] &&
            hs[nx][ny] >= hs[x][y])
          self(self, nx, ny, vis);
      }
    };
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        if ((!i || !j) && !vis[i][j])
          dfs(dfs, i, j, vis);
    vis.assign(m, vector<bool>(n, false));
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        if ((i == m - 1 || j == n - 1) && !vis[i][j])
          dfs(dfs, i, j, vis);

    vector<vector<int>> res;
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        if (can_flow[i][j] == 2)
          res.push_back({i, j});
    return res;
  }
};
// @lc code=end
