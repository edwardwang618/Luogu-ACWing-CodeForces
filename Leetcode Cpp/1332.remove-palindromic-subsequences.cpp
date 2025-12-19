/*
 * @lc app=leetcode id=1332 lang=cpp
 *
 * [1332] Remove Palindromic Subsequences
 */

// @lc code=start
class Solution {
public:
  int removePalindromeSub(string &s) {
    if (s.empty())
      return 0;
    bool is_palin = true;
    for (int i = 0, j = s.size() - 1; i < j; i++, j--)
      if (s[i] != s[j]) {
        is_palin = false;
        break;
      }
    return is_palin ? 1 : 2;
  }
};
// @lc code=end
