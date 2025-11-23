/*
 * @lc app=leetcode id=1374 lang=cpp
 *
 * [1374] Generate a String With Characters That Have Odd Counts
 */

// @lc code=start
class Solution {
 public:
  string generateTheString(int n) {
    string s;
    if (n % 2 == 0) s += 'b', n--;
    s += string(n, 'a');
    return s;
  }
};
// @lc code=end
