/*
 * @lc app=leetcode id=1030 lang=cpp
 *
 * [1030] Matrix Cells in Distance Order
 */

// @lc code=start
class Solution {
 public:
  vector<vector<int>> allCellsDistOrder(int m, int n, int r, int c) {
    vector<vector<int>> res = {{r, c}};
    int dx[] = {1, 1, -1, -1};
    int dy[] = {1, -1, -1, 1};
    for (int d = 1; res.size() < m * n; d++) {
      int x = r - d, y = c;
      for (int i = 0; i < 4; i++)
        for (int j = 0; j < d; j++) {
          if (0 <= x && x < m && 0 <= y && y < n) res.push_back({x, y});
          x += dx[i], y += dy[i];
        }
    }

    return res;
  }
};
// @lc code=end
