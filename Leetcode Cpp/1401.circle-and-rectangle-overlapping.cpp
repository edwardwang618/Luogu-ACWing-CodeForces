/*
 * @lc app=leetcode id=1401 lang=cpp
 *
 * [1401] Circle and Rectangle Overlapping
 */

// @lc code=start
class Solution {
 public:
  bool checkOverlap(int r, int xc, int yc, int x1, int y1, int x2, int y2) {
    x1 -= xc, x2 -= xc;
    y1 -= yc, y2 -= yc;
    if (x1 <= 0 && 0 <= x2 && y1 <= 0 && 0 <= y2) return true;

#define check(x, y) (x * x + y * y <= r * r)

    for (int x = x1; x <= x2; x++)
      if (check(x, y1) || check(x, y2)) return true;

    for (int y = y1; y <= y2; y++)
      if (check(x1, y) || check(x2, y)) return true;

    return false;
  }
};
// @lc code=end
