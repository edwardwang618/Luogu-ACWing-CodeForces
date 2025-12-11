/*
 * @lc app=leetcode id=130 lang=cpp
 *
 * [130] Surrounded Regions
 */

// @lc code=start
class Solution {
public:
  void solve(vector<vector<char>> &g) {
    int m = g.size(), n = g[0].size();
    auto f = [&](char ch1, char ch2) {
      for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
          if ((!i || !j || i == m - 1 || j == n - 1) && g[i][j] == ch1)
            dfs(i, j, ch1, ch2, g);
    };

    f('O', '$');
    [&](char ch1, char ch2) {
      for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
          if (g[i][j] == ch1)
            dfs(i, j, ch1, ch2, g);
    }('O', 'X');
    f('$', 'O');
  }

  static void dfs(int x, int y, char ch1, char ch2, auto &g) {
    static int d[] = {1, 0, -1, 0, 1};
    g[x][y] = ch2;
    for (int k = 0; k < 4; k++) {
      int nx = x + d[k], ny = y + d[k + 1];
      if (0 <= nx && nx < g.size() && 0 <= ny && ny < g[0].size() &&
          g[nx][ny] == ch1)
        dfs(nx, ny, ch1, ch2, g);
    }
  }
};
// @lc code=end
