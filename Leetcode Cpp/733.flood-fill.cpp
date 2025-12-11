/*
 * @lc app=leetcode id=733 lang=cpp
 *
 * [733] Flood Fill
 */

// @lc code=start
class Solution {
public:
  vector<vector<int>> floodFill(vector<vector<int>> &g, int sr, int sc,
                                int col) {
    int old_col = g[sr][sc];
    if (old_col == col)
      return g;
    dfs(sr, sc, old_col, col, g);
    return g;
  }

  static void dfs(int x, int y, int old_col, int col, auto &g) {
    g[x][y] = col;
    static int d[] = {1, 0, -1, 0, 1};
    for (int i = 0; i < 4; i++) {
      int nx = x + d[i], ny = y + d[i + 1];
      if (0 <= nx && nx < g.size() && 0 <= ny && ny < g[0].size() &&
          g[nx][ny] == old_col)
        dfs(nx, ny, old_col, col, g);
    }
  }
};
// @lc code=end
