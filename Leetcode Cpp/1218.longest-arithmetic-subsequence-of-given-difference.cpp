/*
 * @lc app=leetcode id=1218 lang=cpp
 *
 * [1218] Longest Arithmetic Subsequence of Given Difference
 */

// @lc code=start
class Solution {
 public:
  int longestSubsequence(vector<int>& v, int d) {
    unordered_map<int, int> mp;
    int res = 0;
    for (int x : v) {
      if (!mp.count(x - d)) mp[x] = 1;
      else mp[x] = 1 + mp[x - d];

      res = max(res, mp[x]);
    }

    return res;
  }
};
// @lc code=end
