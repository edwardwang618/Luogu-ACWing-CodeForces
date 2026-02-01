/*
 * @lc app=leetcode id=3619 lang=cpp
 *
 * [3619] Count Islands With Total Value Divisible by K
 */

// @lc code=start
class Solution {
public:
  int countIslands(vector<vector<int>> &g, int k) {
    int m = g.size(), n = g[0].size();
    using ll = long long;
    auto dfs = [&](this auto &&dfs, int x, int y) -> ll {
      ll sum = g[x][y];
      g[x][y] = 0;
      static constexpr int d[]{1, 0, -1, 0, 1};
      for (int i = 0; i < 4; i++) {
        int nx = x + d[i], ny = y + d[i + 1];
        if (0 <= nx && nx < m && 0 <= ny && ny < n && g[nx][ny])
          sum += dfs(nx, ny);
      }
      return sum;
    };
    int res = 0;
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        if (g[i][j])
          res += (dfs(i, j) % k == 0);
    return res;
  }
};
// @lc code=end
