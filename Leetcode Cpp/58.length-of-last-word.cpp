/*
 * @lc app=leetcode id=58 lang=cpp
 *
 * [58] Length of Last Word
 */

// @lc code=start
class Solution {
 public:
  int lengthOfLastWord(string s) {
    int i = s.size() - 1;
    while (i >= 0 && s[i] == ' ') i--;
    int j = i;
    while (j >= 0 && s[j] != ' ') j--;
    return i - j;
  }
};
// @lc code=end
