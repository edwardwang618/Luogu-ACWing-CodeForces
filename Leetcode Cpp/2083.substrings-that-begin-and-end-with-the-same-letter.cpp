/*
 * @lc app=leetcode id=2083 lang=cpp
 *
 * [2083] Substrings That Begin and End With the Same Letter
 */

// @lc code=start
class Solution {
 public:
  using LL = long long;
  LL numberOfSubstrings(string s) {
    LL res = 0;
    unordered_map<char, int> mp;
    for (int i = 0; i < s.size(); i++) res += mp[s[i]]++;
    return res + s.size();
  }
};
// @lc code=end
