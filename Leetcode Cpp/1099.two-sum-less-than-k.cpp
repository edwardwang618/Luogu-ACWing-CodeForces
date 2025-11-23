/*
 * @lc app=leetcode id=1099 lang=cpp
 *
 * [1099] Two Sum Less Than K
 */

// @lc code=start
class Solution {
 public:
  int twoSumLessThanK(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    int res = -1, n = nums.size();
    for (int i = 0, j = n - 1;; i++) {
      while (i < j && nums[i] + nums[j] >= k) j--;
      if (i < j)
        res = max(res, nums[i] + nums[j]);
      else
        break;
    }

    return res;
  }
};
// @lc code=end
