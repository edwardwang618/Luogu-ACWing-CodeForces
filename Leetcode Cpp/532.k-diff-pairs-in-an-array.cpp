/*
 * @lc app=leetcode id=532 lang=cpp
 *
 * [532] K-diff Pairs in an Array
 */

// @lc code=start
class Solution {
 public:
  int findPairs(vector<int>& a, int k) {
    unordered_map<int, int> mp;
    for (int x : a) ++mp[x];
    int res = 0;
    for (auto& [x, freq] : mp) res += k ? mp.count(x - k) : freq > 1;
    return res;
  }
};
// @lc code=end
