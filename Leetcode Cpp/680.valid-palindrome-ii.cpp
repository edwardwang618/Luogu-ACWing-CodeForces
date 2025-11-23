/*
 * @lc app=leetcode id=680 lang=cpp
 *
 * [680] Valid Palindrome II
 */

// @lc code=start
class Solution {
 public:
  bool validPalindrome(string s) {
    auto f = [&](int l, int r) {
      for (; l < r; l++, r--)
        if (s[l] != s[r]) return false;
      return true;
    };
    for (int i = 0, j = s.size() - 1; i < j; i++, j--)
      if (s[i] != s[j]) return f(i + 1, j) || f(i, j - 1);
    return true;
  }
};
// @lc code=end
