/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
class Solution {
 public:
  int lengthOfLongestSubstring(string &s) {
    unordered_map<char, int> mp;
    int res = 0;
    for (int i = 0, j = 0; i < s.size(); i++) {
      if (auto it = mp.find(s[i]); it != mp.end()) j = max(it->second + 1, j);
      res = max(res, i - j + 1);
      mp[s[i]] = i;
    }

    return res;
  }
};
// @lc code=end
