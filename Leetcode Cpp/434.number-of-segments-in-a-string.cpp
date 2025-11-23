/*
 * @lc app=leetcode id=434 lang=cpp
 *
 * [434] Number of Segments in a String
 */

// @lc code=start
class Solution {
 public:
  int countSegments(string s) {
    int res = 0;
    for (int i = 0, j; i < s.size(); i++) {
      if (s[i] == ' ') continue;
      j = i;
      while (j < s.size() && s[j] != ' ') j++;
      res++;
      i = j;
    }

    return res;
  }
};
// @lc code=end
