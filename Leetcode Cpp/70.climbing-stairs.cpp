/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 */

// @lc code=start
class Solution {
 public:
  int climbStairs(int n) {
    if (n == 1 || n == 2) return n;
    int n0 = 1, n1 = 2;
    for (int i = 2; i < n; i++) {
      n1 = n0 + n1;
      n0 = n1 - n0;
    }
    return n1;
  }
};
// @lc code=end
