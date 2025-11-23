/*
 * @lc app=leetcode id=329 lang=cpp
 *
 * [329] Longest Increasing Path in a Matrix
 */

// @lc code=start
class Solution {
 public:
  int longestIncreasingPath(vector<vector<int>>& g) {
    vector f(g.size(), vector(g[0].size(), 0));
    int res = 0;
    for (int i = 0; i < g.size(); i++)
      for (int j = 0; j < g[0].size(); j++) res = max(res, dfs(i, j, g, f));
    return res;
  }

  int dfs(int x, int y, auto& g, auto& f) {
    if (f[x][y]) return f[x][y];
    static auto in_bound = [&](int x, int y) {
      return 0 <= x && x < g.size() && 0 <= y && y < g[0].size();
    };
    int res = 1;
    for (int dx = -1; dx <= 1; dx++)
      for (int dy = -1; dy <= 1; dy++)
        if (abs(dx) ^ abs(dy)) {
          int nx = x + dx, ny = y + dy;
          if (in_bound(nx, ny) && g[nx][ny] > g[x][y])
            res = max(res, 1 + dfs(nx, ny, g, f));
        }
    return f[x][y] = res;
  }
};
// @lc code=end
