/*
 * @lc app=leetcode id=32 lang=cpp
 *
 * [32] Longest Valid Parentheses
 */

// @lc code=start
class Solution {
 public:
  int longestValidParentheses(string s) {
    stack<int> stk;
    int res = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '(')
        stk.push(i);
      else {
        if (stk.empty() || s[stk.top()] == ')')
          stk.push(i);
        else {
          stk.pop();
          res = max(res, i - (stk.empty() ? -1 : stk.top()));
        }
      }
    }
    return res;
  }
};
// @lc code=end
