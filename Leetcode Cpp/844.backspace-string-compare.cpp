/*
 * @lc app=leetcode id=844 lang=cpp
 *
 * [844] Backspace String Compare
 */

// @lc code=start
class Solution {
public:
  bool backspaceCompare(string& s, string& t) {
    int i = s.size() - 1, j = t.size() - 1;
    int skip_s = 0, skip_t = 0;
    while (i >= 0 || j >= 0) {
      while (i >= 0) {
        if (s[i] == '#') skip_s++, i--;
        else if (skip_s) skip_s--, i--;
        else break;
      }
      while (j >= 0) {
        if (t[j] == '#') skip_t++, j--;
        else if (skip_t) skip_t--, j--;
        else break;
      }
      if (i >= 0 && j >= 0) {
        if (s[i] != t[j]) return false;
        i--, j--;
      } else if (i >= 0 || j >= 0) return false;
    }
    return true;
  }
};
// @lc code=end
