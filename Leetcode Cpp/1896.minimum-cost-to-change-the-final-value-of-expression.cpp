/*
 * @lc app=leetcode id=1896 lang=cpp
 *
 * [1896] Minimum Cost to Change the Final Value of Expression
 */

// @lc code=start
class Solution {
 public:
#define x first
#define y second
  
  stack<pair<int, int>> stk;
  stack<char> ops;

  int minOperationsToFlip(string s) {
    for (char &c : s) {
      if (isdigit(c)) {
        if (c == '0') stk.push({0, 1});
        else stk.push({1, 0});
      } else if (c == '(') ops.push('(');
      else if (c == ')') {
        while (ops.top() != '(') eval();
        ops.pop();
      } else {
        while (ops.size() && ops.top() != '(') eval();
        ops.push(c);
      }
    }

    while (ops.size()) eval();
    return max(stk.top().x, stk.top().y);
  }

  void eval() {
    auto b = stk.top(); stk.pop();
    auto a = stk.top(); stk.pop();
    char c = ops.top(); ops.pop();

    if (c == '&') {
      auto v0 = {a.x + b.x, a.y + b.x, a.x + b.y};
      auto v1 = {a.y + b.y, a.y + b.x + 1, a.x + b.y + 1};
      stk.push({*min_element(v0.begin(), v0.end()), *min_element(v1.begin(), v1.end())});
    } else {
      auto v0 = {a.x + b.x, a.y + b.x + 1, a.x + b.y + 1};
      auto v1 = {a.y + b.y, a.y + b.x, a.x + b.y};
      stk.push({*min_element(v0.begin(), v0.end()), *min_element(v1.begin(), v1.end())});
    }
  }
};
// @lc code=end
