/*
 * @lc app=leetcode id=1071 lang=cpp
 *
 * [1071] Greatest Common Divisor of Strings
 */

// @lc code=start
class Solution {
 public:
  string gcdOfStrings(string s1, string s2) {
    if (s1 + s2 != s2 + s1) return "";
    return s1.substr(0, gcd(s1.size(), s2.size()));
  }

  int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
  }
};
// @lc code=end
