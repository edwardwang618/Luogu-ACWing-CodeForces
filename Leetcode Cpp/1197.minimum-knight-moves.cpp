/*
 * @lc app=leetcode id=1197 lang=cpp
 *
 * [1197] Minimum Knight Moves
 */

// @lc code=start
class Solution {
 public:
  int minKnightMoves(int x, int y) {
    if (!x && !y) return 0;

    x = abs(x);
    y = abs(y);

    if (x < y) swap(x, y);

    return f(x, y);
  }

  int f(int x, int y) {
    if (x == 1 && !y) return 3;

    if (x == 2 && y == 2) return 4;

    if (y <= x - y) {
      if (x % 2 == 0)
        return x / 2 + (x / 2 - y) % 2;
      else
        return (x + 1) / 2 + ((x + 1) / 2 - (y + 1)) % 2;
    }

    int d = (2 * y - x) / 3;
    if (!d) d = 1;
    x += d;
    y -= d;
    return f(x, y);
  }
};
// @lc code=end
