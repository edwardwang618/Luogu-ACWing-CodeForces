/*
 * @lc app=leetcode id=1020 lang=cpp
 *
 * [1020] Number of Enclaves
 */

// @lc code=start
class Solution {
public:
  int numEnclaves(vector<vector<int>> &g) {
    int m = g.size(), n = g[0].size();
    auto fill = [&](auto&& self, int x, int y) -> void {
      g[x][y] = 0;
      static int d[] = {1, 0, -1, 0, 1};
      for (int k = 0; k < 4; k++) {
        int nx = x + d[k], ny = y + d[k + 1];
        if (0 <= nx && nx < m && 0 <= ny && ny < n && g[nx][ny])
          self(self, nx, ny);
      }
    };

    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        if ((!i || !j || i == m - 1 || j == n - 1) && g[i][j])
          fill(fill, i, j);
    
    int res = 0;
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        if (g[i][j]) res++;
    return res;
  }
};
// @lc code=end
