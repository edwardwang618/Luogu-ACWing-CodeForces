/*
 * @lc app=leetcode id=2556 lang=cpp
 *
 * [2556] Disconnect Path in a Binary Matrix by at Most One Flip
 */

// @lc code=start
class Solution {
public:
  bool isPossibleToCutPath(vector<vector<int>> &g) {
    int m = g.size(), n = g[0].size();
    if (m * n == 1)
      return false;
    auto dfs = [&](this auto &&dfs, int x, int y) -> bool {
      if (x == m - 1 && y == n - 1)
        return true;
      g[x][y] = 0;
      static constexpr int d[]{1, 0, 1};
      for (int k = 0; k < 2; k++) {
        int nx = x + d[k], ny = y + d[k + 1];
        if (0 <= nx && nx < m && 0 <= ny && ny < n && g[nx][ny])
          if (dfs(nx, ny))
            return true;
      }
      return false;
    };
    if (!dfs(0, 0))
      return true;
    g[0][0] = g[m - 1][n - 1] = 1;
    return !dfs(0, 0);
  }
};
// @lc code=end
