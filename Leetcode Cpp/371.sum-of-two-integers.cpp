/*
 * @lc app=leetcode id=371 lang=cpp
 *
 * [371] Sum of Two Integers
 */

// @lc code=start
class Solution {
public:
  int getSum(int a, int b) {
    int res = a;
    while (b) {
      res = a ^ b;
      b = (a & b) << 1;
      a = res;
    }
    return res;
  }
};
// @lc code=end
