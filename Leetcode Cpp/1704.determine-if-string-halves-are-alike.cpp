/*
 * @lc app=leetcode id=1704 lang=cpp
 *
 * [1704] Determine if String Halves Are Alike
 */

// @lc code=start
class Solution {
public:
  bool halvesAreAlike(string &s) {
    auto f = [&](char ch) {
      return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
             ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U';
    };
    int tot = 0, half = 0;
    for (int i = 0; i < s.size(); i++) {
      if (f(s[i])) tot++;
      if (i == s.size() / 2 - 1) half = tot;
    }
    return half * 2 == tot;
  }
};
// @lc code=end
