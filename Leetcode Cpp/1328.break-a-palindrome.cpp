/*
 * @lc app=leetcode id=1328 lang=cpp
 *
 * [1328] Break a Palindrome
 */

// @lc code=start
class Solution {
 public:
  string breakPalindrome(string s) {
    if (s.size() == 1) return "";
    for (int i = 0, j = s.size() - 1; i < j; i++, j--) {
      if (s[i] != 'a') {
        s[i] = 'a';
        return s;
      }
    }

    s.back() = 'b';
    return s;
  }
};
// @lc code=end
