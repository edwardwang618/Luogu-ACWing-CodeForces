/*
 * @lc app=leetcode id=150 lang=cpp
 *
 * [150] Evaluate Reverse Polish Notation
 */

// @lc code=start
class Solution {
 public:
  int evalRPN(vector<string>& v) {
    stack<int> stk;
    constexpr array<char, 4> ops{'+', '-', '*', '/'};
    auto f = [&](stack<int>& stk, char op) -> int {
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
    for (auto& s : v)
      if (s.size() == 1 && find(ops.begin(), ops.end(), s[0]) != ops.end())
        stk.push(f(stk, s[0]));
      else stk.push(stoi(s));
    return stk.top();
  }
};
// @lc code=end
