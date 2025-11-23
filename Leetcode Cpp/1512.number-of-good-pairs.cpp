/*
 * @lc app=leetcode id=1512 lang=cpp
 *
 * [1512] Number of Good Pairs
 */

// @lc code=start
class Solution {
 public:
  int numIdenticalPairs(vector<int>& a) {
    unordered_map<int, int> mp;
    int res = 0;
    for (int x : a) {
      res += mp[x];
      mp[x]++;
    }
    return res;
  }
};
// @lc code=end
