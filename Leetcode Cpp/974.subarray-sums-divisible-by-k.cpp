/*
 * @lc app=leetcode id=974 lang=cpp
 *
 * [974] Subarray Sums Divisible by K
 */

// @lc code=start
class Solution {
 public:
  int subarraysDivByK(vector<int>& a, int k) {
    int res = 0;
    unordered_map<int, int> mp;
    mp[0] = 1;
    for (int i = 0, s = 0; i < a.size(); i++) {
      s = (s + a[i] % k + k) % k;
      auto [it, ins] = mp.try_emplace(s, 0);
      res += it->second;
      ++it->second;
    }
    return res;
  }
};
// @lc code=end
