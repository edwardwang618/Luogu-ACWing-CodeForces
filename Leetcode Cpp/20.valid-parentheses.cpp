/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

// @lc code=start
class Solution {
 public:
  bool isValid(string s) {
    stack<char> stk;
    auto f = [&](char c1, char c2) {
      return ((c1 == '(' && c2 == ')') ||
              (c1 == '[' && c2 == ']' || (c1 == '{' && c2 == '}')));
    };
    for (char ch : s)
      if (ch == '(' || ch == '[' || ch == '{')
        stk.push(ch);
      else {
        if (stk.empty()) return false;
        if (!f(stk.top(), ch)) return false;
        stk.pop();
      }
    return stk.empty();
  }
};
// @lc code=end
