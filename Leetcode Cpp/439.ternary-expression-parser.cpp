/*
 * @lc app=leetcode id=439 lang=cpp
 *
 * [439] Ternary Expression Parser
 */

// @lc code=start
class Solution {
 public:
  string parseTernary(string s) {
    stack<char> stk;
    for (int i = s.size() - 1; i >= 0; i--) {
      char c = s[i];
      if (stk.size() && stk.top() == '?') {
        stk.pop();
        char c1 = stk.top(); stk.pop();
        stk.pop();
        char c2 = stk.top(); stk.pop();
        if (c == 'T') stk.push(c1);
        else stk.push(c2);
      } else stk.push(c);
    }

    return string(1, stk.top());
  }
};
// @lc code=end
