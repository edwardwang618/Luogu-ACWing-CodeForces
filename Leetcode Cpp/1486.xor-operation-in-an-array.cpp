/*
 * @lc app=leetcode id=1486 lang=cpp
 *
 * [1486] XOR Operation in an Array
 */

// @lc code=start
class Solution {
 public:
  int xorOperation(int n, int start) {
    int res = 0;
    while (n--) res ^= start, start += 2;
    return res;
  }
};
// @lc code=end
