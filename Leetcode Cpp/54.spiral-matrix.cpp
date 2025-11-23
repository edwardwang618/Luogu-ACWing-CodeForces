/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 */

// @lc code=start
class Solution {
 public:
  vector<int> spiralOrder(vector<vector<int>>& a) {
    vector<int> res;
    int m = a.size(), n = a[0].size();
    int x = 0, y = 0;
    static constexpr array<array<int, 2>, 4> d{
        {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}};
    int dir = 0;
    while (true) {
      res.push_back(a[x][y]);
      a[x][y] = 101;
      if (res.size() == m * n) return res;
      while (true) {
        int nx = x + d[dir][0], ny = y + d[dir][1];
        if (0 <= nx && nx < m && 0 <= ny && ny < n && a[nx][ny] != 101) {
          x = nx, y = ny;
          break;
        }
        dir = (dir + 1) % 4;
      }
    }
    return res;
  }
};
// @lc code=end
