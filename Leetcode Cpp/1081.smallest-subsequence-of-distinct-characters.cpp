/*
 * @lc app=leetcode id=1081 lang=cpp
 *
 * [1081] Smallest Subsequence of Distinct Characters
 */

// @lc code=start
class Solution {
 public:
  string smallestSubsequence(string s) {
    unordered_map<char, int> mp;
    for (int i = 0; i < s.size(); i++) mp[s[i]] = i;
    bool used[26];
    memset(used, 0, sizeof used);
    string res;
    for (int i = 0; i < s.size(); i++) {
      if (used[s[i] - 'a']) continue;
      while (res.size() && res.back() > s[i] && mp[res.back()] > i) {
        used[res.back() - 'a'] = false;
        res.pop_back();
      }
      res += s[i];
      used[s[i] - 'a'] = true;
    }
    return res;
  }
};
// @lc code=end
