/*
 * @lc app=leetcode id=150 lang=cpp
 *
 * [150] Evaluate Reverse Polish Notation
 */

// @lc code=start
class Solution {
public:
  int evalRPN(vector<string> &v) {
    stack<int> stk;
    auto f = [&](stack<int> &stk, char op) {
      int b = stk.top(); stk.pop();
      int a = stk.top(); stk.pop();
      switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
      }
      return -1;
    };
    for (auto &s : v)
      if (char ch = s[0];
          s.size() == 1 && (ch == '+' || ch == '-' || ch == '*' || ch == '/'))
        stk.push(f(stk, s[0]));
      else stk.push(stoi(s));
    return stk.top();
  }
};
// @lc code=end
