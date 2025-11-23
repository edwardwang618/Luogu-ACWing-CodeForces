/*
 * @lc app=leetcode id=991 lang=cpp
 *
 * [991] Broken Calculator
 */

// @lc code=start
class Solution {
 public:
  int brokenCalc(int x, int y) {
    int res = 0;
    while (y > x) {
      y % 2 ? y++ : y >>= 1;
      res++;
    }

    return res + x - y;
  }
};
// @lc code=end
