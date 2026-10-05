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
      int y = x % 10;
      if (res > 0 && res > (numeric_limits<int>::max() - y) / 10) return 0;
      if (res < 0 && res < (numeric_limits<int>::min() - y) / 10) return 0;
      res = res * 10 + y;
      x /= 10;
    }
    return res;
  }
};
// @lc code=end
