/*
 * @lc app=leetcode id=1017 lang=cpp
 *
 * [1017] Convert to Base -2
 */

// @lc code=start
class Solution {
 public:
  string baseNeg2(int n) {
    if (!n) return "0";
    string s;
    while (n) {
      s += to_string(n & 1);
      n -= n & 1;
      n /= -2;
    }
    reverse(s.begin(), s.end());
    return s;
  }
};
// @lc code=end