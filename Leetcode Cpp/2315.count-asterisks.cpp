/*
 * @lc app=leetcode id=2315 lang=cpp
 *
 * [2315] Count Asterisks
 */

// @lc code=start
class Solution {
 public:
  int countAsterisks(string s) {
    int res = 0;
    bool cnt = true;
    for (char ch : s)
      if (ch == '|') cnt ^= 1;
      else if (cnt && ch == '*') res++;
    return res;
  }
};
// @lc code=end
