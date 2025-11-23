/*
 * @lc app=leetcode id=18 lang=cpp
 *
 * [18] 4Sum
 */

// @lc code=start
class Solution {
 public:
  vector<vector<int>> fourSum(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;

    for (int i = 0; i < nums.size(); ++i) {
      if (i > 0 && nums[i] == nums[i - 1]) continue;
      for (int j = i + 1; j < nums.size(); ++j) {
        if (j > i + 1 && nums[j] == nums[j - 1]) continue;
        int l = j + 1, r = nums.size() - 1;
        while (l < r) {
          if (l > j + 1 && nums[l] == nums[l - 1]) {
            ++l;
            continue;
          }
          if (r < nums.size() - 1 && nums[r] == nums[r + 1]) {
            --r;
            continue;
          }
          long long sum = (long long)nums[i] + nums[j] + nums[l] + nums[r];
          if (sum < target)
            ++l;
          else if (sum > target)
            --r;
          else {
            res.push_back({nums[i], nums[j], nums[l], nums[r]});
            ++l;
            --r;
          }
        }
      }
    }

    return res;
  }
};
// @lc code=end
