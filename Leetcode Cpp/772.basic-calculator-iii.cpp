/*
 * @lc app=leetcode id=772 lang=cpp
 *
 * [772] Basic Calculator III
 */

// @lc code=start
class Solution {
 public:
  using ll = long long;
  int calculate(string s) {
    unordered_map<char, int> mp{
        {'(', 1}, {'+', 2}, {'-', 2}, {'*', 3}, {'/', 3}};
    stack<char> ops;
    stack<ll> stk;
    auto calc = [&](auto &stk, auto &ops) {
      ll b = stk.top(); stk.pop();
      ll a = stk.top(); stk.pop();
      switch (ops.top()) {
        case '+': stk.push(a + b); break;
        case '-': stk.push(a - b); break;
        case '*': stk.push(a * b); break;
        case '/': stk.push(a / b); break;
      }
      ops.pop();
    };
    for (int i = 0; i < s.size(); i++) {
      char ch = s[i];
      if (ch == '(') ops.push('(');
      else if (isdigit(ch)) {
        int j = i;
        while (j < s.size() && isdigit(s[j])) j++;
        stk.push(stol(s.substr(i, j - i)));
        i = j - 1;
      } else if (ch == ')') {
        while (ops.top() != '(') calc(stk, ops);
        ops.pop();
      } else if (ch != ' ') {
        while (ops.size() && mp[ops.top()] >= mp[ch])
          calc(stk, ops);
        ops.push(ch);
      }
    }

    while (ops.size()) calc(stk, ops);
    return (int)stk.top();
  }
};
// @lc code=end
