/*
 * @lc app=leetcode id=424 lang=cpp
 *
 * [424] Longest Repeating Character Replacement
 */

// @lc code=start
class Solution {
 public:
  int characterReplacement(string s, int k) {
    int res = 0;
    for (char ch = 'A'; ch <= 'Z'; ch++)
      for (int i = 0, j = 0, cnt = 0; i < s.size(); i++) {
        if (s[i] == ch) cnt++;
        while (i - j + 1 - cnt > k)
          if (s[j++] == ch) cnt--;
        res = max(res, i - j + 1);
      }
    return res;
  }
};
// @lc code=end
