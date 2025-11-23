/*
 * @lc app=leetcode id=258 lang=cpp
 *
 * [258] Add Digits
 */

// @lc code=start
class Solution {
 public:
  int addDigits(int x) { return (x - 1) % 9 + 1; }
};
// @lc code=end
