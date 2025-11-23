/*
 * @lc app=leetcode id=2091 lang=cpp
 *
 * [2091] Removing Minimum and Maximum From Array
 */

// @lc code=start
class Solution {
 public:
  int minimumDeletions(vector<int>& nums) {
    int n = nums.size();
    int min_id = 0, max_id = 0;
    for (int i = 1; i < n; i++) {
      if (nums[i] < nums[min_id]) min_id = i;
      if (nums[i] > nums[max_id]) max_id = i;
    }

    if (min_id > max_id) swap(min_id, max_id);
    int res = min(max_id + 1, n - min_id);
    res = min(res, min_id + 1 + n - max_id);
    return res;
  }
};
// @lc code=end
