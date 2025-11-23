/*
 * @lc app=leetcode id=227 lang=cpp
 *
 * [227] Basic Calculator II
 */

// @lc code=start
class Solution {
 public:
  int calculate(string s) {
    int a = 0, b = 1;
    char op = '*';
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == ' ') continue;
      if (isdigit(s[i])) {
        int j = i;
        int x = 0;
        while (j < s.size() && isdigit(s[j])) x = x * 10 + (s[j++] - '0');
        i = j - 1;
        if (op == '+') a += b, b = x;
        else if (op == '-') a += b, b = -x;
        else if (op == '*') b *= x;
        else b /= x;
      } else op = s[i];
    }

    return a + b;
  }
};
// @lc code=end

// class Solution {
//  public:
//   int calculate(string s) {
//     auto f = [](int x, int y, char op) {
//       switch (op) {
//         case '+': return x + y;
//         case '-': return x - y;
//         case '*': return x * y;
//         case '/': return x / y;
//       }

//       return 0;
//     };
//     stack<int> stk;
//     stack<char> ops;
//     unordered_map<char, int> mp = {{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}};
//     for (int i = 0; i < s.size(); i++) {
//       if (s[i] == ' ') continue;
//       if (isdigit(s[i])) {
//         int x = 0;
//         int j = i;
//         while (j < s.size() && isdigit(s[j])) x = x * 10 + (s[j++] - '0');
//         i = j - 1;
//         stk.push(x);
//       } else {
//         while (ops.size() && mp[ops.top()] >= mp[s[i]]) {
//           char op = ops.top(); ops.pop();
//           int n2 = stk.top(); stk.pop();
//           int n1 = stk.top(); stk.pop();
//           stk.push(f(n1, n2, op));
//         }
//         ops.push(s[i]);
//       }
//     }

//     while (stk.size() > 1) {
//       char op = ops.top(); ops.pop();
//       int n2 = stk.top(); stk.pop();
//       int n1 = stk.top(); stk.pop();
//       stk.push(f(n1, n2, op));
//     }

//     return stk.top();
//   }
// };