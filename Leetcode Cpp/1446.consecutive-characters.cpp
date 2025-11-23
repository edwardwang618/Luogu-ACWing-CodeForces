/*
 * @lc app=leetcode id=1446 lang=cpp
 *
 * [1446] Consecutive Characters
 */

// @lc code=start
class Solution {
 public:
  int maxPower(string s) {
    int res = 0;
    for (int i = 0; i < s.size(); i++) {
      int j = i;
      while (j < s.size() && s[i] == s[j]) j++;
      res = max(res, j - i);
      i = j - 1;
    }
    return res;
  }
};
// @lc code=end
