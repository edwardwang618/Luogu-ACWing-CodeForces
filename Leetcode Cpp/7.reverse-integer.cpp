/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 */

// @lc code=start
class Solution {
 public:
  int reverse(int x) {
    int res = 0;
    while (x) {
      // 如果下一步就要溢出了，则返回0
      if (res > 0 && res > (INT_MAX - x % 10) / 10) return 0;
      if (res < 0 && res < (INT_MIN - x % 10) / 10) return 0;
      res = res * 10 + x % 10;
      x /= 10;
    }

    return res;
  }
};
// @lc code=end
