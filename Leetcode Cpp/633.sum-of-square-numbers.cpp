/*
 * @lc app=leetcode id=633 lang=cpp
 *
 * [633] Sum of Square Numbers
 */

// @lc code=start
class Solution {
 public:
  bool judgeSquareSum(int c) {
    // 枚举c的素因子
    for (int i = 2; i * i <= c; i++) {
      int count = 0;
      while (c % i == 0) {
        c /= i;
        count++;
      }

      // 如果该因子是4k + 3的形式并且次数不是偶数，则返回false
      if (i % 4 == 3 && count % 2 != 0) return false;
    }

    // 最后考虑一下c本身是素数的情形
    return c % 4 != 3;
  }
};
// @lc code=end
