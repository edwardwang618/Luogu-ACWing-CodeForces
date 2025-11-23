/*
 * @lc app=leetcode id=259 lang=cpp
 *
 * [259] 3Sum Smaller
 */

// @lc code=start
class Solution {
 public:
  int threeSumSmaller(vector<int>& nums, int target) {
    if (nums.size() < 3) return 0;
    sort(nums.begin(), nums.end());
    int res = 0;
    for (int i = 0; i < nums.size() - 2; i++) {
      int l = i + 1, r = nums.size() - 1;
      while (l < r) {
        int sum = nums[l] + nums[r];
        if (sum + nums[i] < target) {
          res += r - l;
          l++;
        } else
          r--;
      }
    }

    return res;
  }
};
// @lc code=end
