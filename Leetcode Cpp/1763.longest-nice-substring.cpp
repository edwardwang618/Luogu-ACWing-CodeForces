/*
 * @lc app=leetcode id=1763 lang=cpp
 *
 * [1763] Longest Nice Substring
 */

// @lc code=start
class Solution {
 public:
  string longestNiceSubstring(string s) {
    string res;
    for (int i = 0; i < s.size(); i++) {
      int x = 0, y = 0;
      for (int j = i; j < s.size(); j++) {
        islower(s[j]) ? x |= 1 << s[j] - 'a' : y |= 1 << s[j] - 'A';
        if (x == y && j - i + 1 > res.size()) res = s.substr(i, j - i + 1);
      }
    }

    return res;
  }
};
// @lc code=end
