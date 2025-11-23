/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 */

// @lc code=start
class Solution {
 public:
  int d[5] = {-1, 0, 1, 0, -1};
  int numIslands(vector<vector<char>>& g) {
    int res = 0;
    for (int i = 0; i < g.size(); i++)
      for (int j = 0; j < g[0].size(); j++) {
        if (g[i][j] == '1') {
          dfs(i, j, g);
          res++;
        }
      }

    return res;
  }

  void dfs(int x, int y, auto& g) {
    g[x][y] = '0';
    for (int k = 0; k < 4; k++) {
      int nx = x + d[k], ny = y + d[k + 1];
      if (0 <= nx && nx < g.size() && 0 <= ny && ny < g[0].size() &&
          g[nx][ny] == '1')
        dfs(nx, ny, g);
    }
  }
};
// @lc code=end
