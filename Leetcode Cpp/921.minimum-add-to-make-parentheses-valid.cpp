/*
 * @lc app=leetcode id=921 lang=cpp
 *
 * [921] Minimum Add to Make Parentheses Valid
 */

// @lc code=start
class Solution {
 public:
  int minAddToMakeValid(string s) {
    int res = 0, l = 0, r = 0;
    for (int i = 0; i < s.size(); i++) {
      s[i] == '(' ? l++ : r++;
      if (l < r) res++, l++;
    }
    return res + l - r;
  }
};
// @lc code=end
