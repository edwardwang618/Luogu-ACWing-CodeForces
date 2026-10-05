/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

// @lc code=start
class Solution {
public:
  bool isValid(const string& s) {
    stack<char> stk;
    for (char ch : s) {
      if (ch == '(' || ch == '[' || ch == '{') stk.push(ch);
      else  {
        if (stk.empty() || abs(ch - stk.top()) > 2) return false;
        stk.pop();
      }
    }
    return stk.empty();
  }
};
// @lc code=end
