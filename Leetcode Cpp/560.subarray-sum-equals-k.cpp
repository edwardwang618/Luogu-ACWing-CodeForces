/*
 * @lc app=leetcode id=560 lang=cpp
 *
 * [560] Subarray Sum Equals K
 */

// @lc code=start
class Solution {
 public:
  int subarraySum(vector<int>& a, int k) {
    unordered_map<int, int> mp;
    mp[0] = 1;
    int res = 0;
    for (int i = 0, s = 0; i < a.size(); i++) {
      s += a[i];
      res += mp[s - k];
      mp[s]++;
    }

    return res;
  }
};
// @lc code=end
