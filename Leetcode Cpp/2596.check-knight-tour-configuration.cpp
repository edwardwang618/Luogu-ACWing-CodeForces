/*
 * @lc app=leetcode id=2596 lang=cpp
 *
 * [2596] Check Knight Tour Configuration
 */

// @lc code=start
class Solution {
public:
  bool checkValidGrid(vector<vector<int>> &g) {
    if (g[0][0])
      return false;
    static constexpr int dx[]{-2, -2, -1, -1, 1, 1, 2, 2};
    static constexpr int dy[]{1, -1, 2, -2, 2, -2, 1, -1};
    int n = g.size();
    int x = 0, y = 0;
    for (int idx = 1; idx < n * n; idx++) {
      bool found = false;
      for (int k = 0; k < 8; k++) {
        int nx = x + dx[k], ny = y + dy[k];
        if (0 <= nx && nx < n && 0 <= ny && ny < n && g[nx][ny] == idx) {
          x = nx, y = ny;
          found = true;
          break;
        }
      }
      if (!found)
        return false;
    }
    return true;
  }
};
// @lc code=end
