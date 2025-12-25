/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 */

// @lc code=start
class Solution {
public:
  int numIslands(vector<vector<char>> &g) {
    int m = g.size(), n = g[0].size();
    int res = 0;
    auto dfs = [&](this auto &&dfs, int x, int y) -> void {
      g[x][y] = '0';
      static int d[] = {1, 0, -1, 0, 1};
      for (int k = 0; k < 4; k++) {
        int nx = x + d[k], ny = y + d[k + 1];
        if (0 <= nx && nx < m && 0 <= ny && ny < n && g[nx][ny] == '1')
          dfs(nx, ny);
      }
    };
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        if (g[i][j] == '1') {
          dfs(i, j);
          res++;
        }
    return res;
  }
};
// @lc code=end
