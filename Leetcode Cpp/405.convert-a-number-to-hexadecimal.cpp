/*
 * @lc app=leetcode id=405 lang=cpp
 *
 * [405] Convert a Number to Hexadecimal
 */

// @lc code=start
class Solution {
 public:
  string toHex(int x) {
    unsigned y = x;
    string s;
    if (!y) return "0";
    while (y) {
      x = y & 0xf;
      if (x < 10) s += '0' + x;
      else s += x - 10 + 'a';
      y >>= 4;
    }
    reverse(s.begin(), s.end());
    return s;
  }
};
// @lc code=end
