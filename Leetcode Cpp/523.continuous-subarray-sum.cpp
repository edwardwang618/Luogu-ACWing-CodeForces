/*
 * @lc app=leetcode id=523 lang=cpp
 *
 * [523] Continuous Subarray Sum
 */

// @lc code=start
class Solution {
 public:
  bool checkSubarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> mp;
    mp[0] = -1;
    for (int i = 0, s = 0; i < nums.size(); i++) {
      s = (s + nums[i]) % k;
      auto [it, ins] = mp.try_emplace(s, i);
      if (!ins && i - it->second >= 2) return true;
    }

    return false;
  }
};
// @lc code=end
