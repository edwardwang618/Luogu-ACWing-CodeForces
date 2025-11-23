/*
 * @lc app=leetcode id=791 lang=cpp
 *
 * [791] Custom Sort String
 */

// @lc code=start
class Solution {
 public:
  string customSortString(string order, string s) {
    int cnt[26] = {0};
    for (int i = 0; i < s.size(); i++) cnt[s[i] - 'a']++;
    s = "";
    for (char ch : order)
      if (cnt[ch - 'a']) {
        s += string(cnt[ch - 'a'], ch);
        cnt[ch - 'a'] = 0;
      }
    for (int i = 0; i < 26; i++)
      while (cnt[i]--) s += 'a' + i;
    return s;
  }
};
// @lc code=end
