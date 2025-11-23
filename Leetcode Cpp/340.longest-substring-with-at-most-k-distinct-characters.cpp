/*
 * @lc app=leetcode id=340 lang=cpp
 *
 * [340] Longest Substring with At Most K Distinct Characters
 */

// @lc code=start
class Solution {
 public:
  int lengthOfLongestSubstringKDistinct(string s, int k) {
    unordered_map<char, int> mp;
    int res = 0;
    for (int i = 0, j = 0; i < s.size(); i++) {
      mp[s[i]]++;
      while (mp.size() > k) {
        if (!--mp[s[j]]) mp.erase(s[j]);
        j++;
      }
      res = max(res, i - j + 1);
    }
    return res;
  }
};
// @lc code=end
