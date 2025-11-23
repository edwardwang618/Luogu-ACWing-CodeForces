/*
 * @lc app=leetcode id=1221 lang=cpp
 *
 * [1221] Split a String in Balanced Strings
 */

// @lc code=start
class Solution {
 public:
  int balancedStringSplit(string s) {
    int cnt[2]{0, 0}, res = 0;
    for (char ch : s) {
      (ch == 'R' ? cnt[0] : cnt[1])++;
      if (cnt[0] == cnt[1]) res++;
    }

    return res;
  }
};
// @lc code=end
