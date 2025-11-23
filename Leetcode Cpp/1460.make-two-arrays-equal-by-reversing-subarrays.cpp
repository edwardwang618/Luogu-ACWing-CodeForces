/*
 * @lc app=leetcode id=1460 lang=cpp
 *
 * [1460] Make Two Arrays Equal by Reversing Subarrays
 */

// @lc code=start
class Solution {
 public:
  bool canBeEqual(vector<int>& target, vector<int>& arr) {
    unordered_map<int, int> mp;
    for (auto& x : target) mp[x]++;
    for (auto& x : arr) {
      if (!mp[x]) return false;
      mp[x]--;
    }
    return true;
  }
};
// @lc code=end
