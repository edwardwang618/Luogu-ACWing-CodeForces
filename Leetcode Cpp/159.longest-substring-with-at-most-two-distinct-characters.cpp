/*
 * @lc app=leetcode id=159 lang=cpp
 *
 * [159] Longest Substring with At Most Two Distinct Characters
 */

// @lc code=start
class Solution {
 public:
  int lengthOfLongestSubstringTwoDistinct(string s) {
    int res = 0;
    unordered_map<char, int> mp;
    for (int i = 0, j = 0; i < s.size(); i++) {
      mp[s[i]]++;
      while (mp.size() > 2) {
        mp[s[j]]--;
        if (!mp[s[j]]) mp.erase(s[j]);
        j++;
      }

      res = max(res, i - j + 1);
    }

    return res;
  }
};
// @lc code=end
