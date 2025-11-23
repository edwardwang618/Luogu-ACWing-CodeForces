/*
 * @lc app=leetcode id=476 lang=cpp
 *
 * [476] Number Complement
 */

// @lc code=start
class Solution {
 public:
  int findComplement(int num) {
    int res = 0, pos = 0;
    while (num) {
      res += (num & 1 ^ 1) << pos;
      pos++;
      num >>= 1;
    }
    return res;
  }
};
// @lc code=end
