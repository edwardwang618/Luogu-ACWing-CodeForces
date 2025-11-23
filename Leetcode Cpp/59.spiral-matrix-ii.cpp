/*
 * @lc app=leetcode id=59 lang=cpp
 *
 * [59] Spiral Matrix II
 */

// @lc code=start
class Solution {
 public:
  vector<vector<int>> generateMatrix(int n) {
    vector res(n, vector(n, 0));
    int cnt = 1, x = 0, y = 0, dir = 0;
    static constexpr array<array<int, 2>, 4> d{
        {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}};
    auto f = [&](int x, int y) {
      return 0 <= x && x < n && 0 <= y && y < n && !res[x][y];
    };
    while (cnt <= n * n) {
      res[x][y] = cnt++;
      int nx = x + d[dir][0], ny = y + d[dir][1];
      if (f(nx, ny))
        x = nx, y = ny;
      else {
        dir = (dir + 1) % 4;
        x += d[dir][0], y += d[dir][1];
      }
    }
    return res;
  }
};
// @lc code=end
