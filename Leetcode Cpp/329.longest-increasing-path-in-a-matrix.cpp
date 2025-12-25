/*
 * @lc app=leetcode id=329 lang=cpp
 *
 * [329] Longest Increasing Path in a Matrix
 */

// @lc code=start
class Solution {
public:
  int longestIncreasingPath(vector<vector<int>> &g) {
    int m = g.size(), n = g[0].size();
    auto id = [&](int x, int y) { return x * n + y; };
    vector<int> f(m * n);
    auto dfs = [&](this auto &&dfs, int x, int y) -> int {
      int idxy = id(x, y);
      if (f[idxy])
        return f[idxy];
      int res = 1;
      static int d[] = {1, 0, -1, 0, 1};
      for (int k = 0; k < 4; k++) {
        int nx = x + d[k], ny = y + d[k + 1];
        if (0 <= nx && nx < m && 0 <= ny && ny < n && g[nx][ny] > g[x][y])
          res = max(res, 1 + dfs(nx, ny));
      }
      return f[idxy] = res;
    };
    int res = 0;
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        res = max(res, dfs(i, j));
    return res;
  }
};
// @lc code=end
