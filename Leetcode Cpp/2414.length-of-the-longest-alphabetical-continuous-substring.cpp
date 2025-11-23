/*
 * @lc app=leetcode id=2414 lang=cpp
 *
 * [2414] Length of the Longest Alphabetical Continuous Substring
 */

// @lc code=start
class Solution {
 public:
  int longestContinuousSubstring(string s) {
    int res = 0;
    for (int i = 0; i < s.size(); i++) {
      int j = i;
      while (j + 1 < s.size() && s[j + 1] == s[j] + 1) j++;
      res = max(res, j - i + 1);
      i = j;
    }
    return res;
  }
};
// @lc code=end
