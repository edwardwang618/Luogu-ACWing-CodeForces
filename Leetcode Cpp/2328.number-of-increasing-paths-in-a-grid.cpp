/*
 * @lc app=leetcode id=2328 lang=cpp
 *
 * [2328] Number of Increasing Paths in a Grid
 */

// @lc code=start
class Solution {
public:
  int countPaths(vector<vector<int>> &g) {
    static constexpr int MOD = 1e9 + 7;
    int m = g.size(), n = g[0].size();
    vector<vector<int>> f(m, vector<int>(n, -1));
    auto dfs = [&](this auto &&dfs, int x, int y) -> int {
      if (~f[x][y]) return f[x][y];
      int cnt = 1;
      static constexpr int d[] = {1, 0, -1, 0, 1};
      for (int k = 0; k < 4; k++) {
        int nx = x + d[k], ny = y + d[k + 1];
        if (0 <= nx && nx < m && 0 <= ny && ny < n && g[nx][ny] > g[x][y])
          cnt = (cnt + dfs(nx, ny)) % MOD;
      }
      return f[x][y] = cnt;
    };
    
    int res = 0;
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        res = (res + dfs(i, j)) % MOD;
    return res;
  }
};
// @lc code=end
