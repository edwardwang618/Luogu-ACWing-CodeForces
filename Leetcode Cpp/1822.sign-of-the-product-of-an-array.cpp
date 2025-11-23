/*
 * @lc app=leetcode id=1822 lang=cpp
 *
 * [1822] Sign of the Product of an Array
 */

// @lc code=start
class Solution {
 public:
  int arraySign(vector<int>& nums) {
    int res = 1;
    for (int x : nums)
      if (!x)
        return 0;
      else if (x < 0)
        res *= -1;
    return res;
  }
};
// @lc code=end
