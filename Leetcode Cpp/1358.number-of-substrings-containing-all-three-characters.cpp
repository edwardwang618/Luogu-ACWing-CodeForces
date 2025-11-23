/*
 * @lc app=leetcode id=1358 lang=cpp
 *
 * [1358] Number of Substrings Containing All Three Characters
 */

// @lc code=start
class Solution {
 public:
  int numberOfSubstrings(string s) {
    int res = 0, n = s.size();
    unordered_map<char, int> mp;
    for (int i = 0, j = 0; i < n; i++) {
      mp[s[i]]++;
      while (mp['a'] && mp['b'] && mp['c']) mp[s[j++]]--;
      res += j;
    }
    return res;
  }
};
// @lc code=end
