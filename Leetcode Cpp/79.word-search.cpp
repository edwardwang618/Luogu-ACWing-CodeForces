/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 */

// @lc code=start
class Solution {
public:
  bool exist(vector<vector<char>> &g, string s) {
    int m = g.size(), n = g[0].size();
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        if (dfs(0, s, i, j, g, m, n))
          return true;
    return false;
  }

  static bool dfs(int u, string &s, int x, int y, auto &g, int m, int n) {
    if (g[x][y] != s[u])
      return false;
    if (u == s.size() - 1)
      return true;
    char ch = g[x][y];
    g[x][y] = '$';
    static int d[] = {1, 0, -1, 0, 1};
    for (int i = 0; i < 4; i++) {
      int nx = x + d[i], ny = y + d[i + 1];
      if (0 <= nx && nx < m && 0 <= ny && ny < n && g[nx][ny] != '$' &&
          dfs(u + 1, s, nx, ny, g, m, n))
        return true;
    }
    g[x][y] = ch;
    return false;
  }
};
// @lc code=end
