/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 */

// @lc code=start
class Solution {
 public:
  bool exist(vector<vector<char>>& g, string s) {
    for (int i = 0; i < g.size(); i++)
      for (int j = 0; j < g[0].size(); j++)
        if (dfs(0, s, i, j, g)) return true;
    return false;
  }

  bool dfs(int u, string& s, int x, int y, vector<vector<char>>& g) {
    if (u == s.size()) return true;
    if (x < 0 || x >= g.size() || y < 0 || y >= g[0].size()) return false;
    if (g[x][y] == '$' || g[x][y] != s[u]) return false;
    char ch = g[x][y];
    g[x][y] = '$';
    static int d[] = {-1, 0, 1, 0, -1};
    for (int i = 0; i < 4; i++) {
      int nx = x + d[i], ny = y + d[i + 1];
      if (dfs(u + 1, s, nx, ny, g)) return true;
    }
    g[x][y] = ch;
    return false;
  }
};
// @lc code=end
