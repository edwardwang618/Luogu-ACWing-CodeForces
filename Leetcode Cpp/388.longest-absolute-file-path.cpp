/*
 * @lc app=leetcode id=388 lang=cpp
 *
 * [388] Longest Absolute File Path
 */

// @lc code=start
class Solution {
 public:
  int lengthLongestPath(string s) {
    stack<int> stk;
    int res = 0;
    for (int i = 0, len = 0; i < s.size(); i++) {
      int dep = 0;
      while (i < s.size() && s[i] == '\t') dep++, i++;
      while (stk.size() > dep) len -= stk.top(), stk.pop();
      int j = i;
      bool has_dot = false;
      while (j < s.size() && s[j] != '\n') {
        if (s[j] == '.') has_dot = true;
        j++;
      }

      len += j - i;
      stk.push(j - i);
      if (has_dot) res = max(res, len + (int)stk.size() - 1);
      i = j;
    }

    return res;
  }
};
// @lc code=end
