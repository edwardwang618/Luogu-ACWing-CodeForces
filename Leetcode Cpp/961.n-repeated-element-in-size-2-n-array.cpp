/*
 * @lc app=leetcode id=961 lang=cpp
 *
 * [961] N-Repeated Element in Size 2N Array
 */

// @lc code=start
class Solution {
 public:
  int repeatedNTimes(vector<int>& nums) {
    for (int i = 0; i < nums.size(); i += 2)
      if (nums[i] == nums[i + 1]) return nums[i];

    if (nums[0] == nums[2] || nums[0] == nums[3]) return nums[0];
    return nums[1];
  }
};
// @lc code=end
