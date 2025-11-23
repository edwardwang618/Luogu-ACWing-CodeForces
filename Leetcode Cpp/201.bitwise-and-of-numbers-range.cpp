/*
 * @lc app=leetcode id=201 lang=cpp
 *
 * [201] Bitwise AND of Numbers Range
 */

// @lc code=start
class Solution {
 public:
  int rangeBitwiseAnd(int l, int r) {
    int res = 0;
    for (int i = 30; i >= 0; i--) {
      if ((l >> i & 1) != (r >> i & 1)) break;
      res |= (l >> i & 1) << i;
    }
    return res;
  }
};
// @lc code=end
