/*
 * @lc app=leetcode id=224 lang=cpp
 *
 * [224] Basic Calculator
 */

// @lc code=start
class Solution {
 public:
  using ll = long long;
  ll dfs(int &k, string& s) {
    ll a = 0, b = 1;
    char op = '*';
    auto f = [](ll &a, ll &b, ll x, char op) {
      if (op == '+') a += b, b = x;
      else if (op == '-') a += b, b = -x;
      else if (op == '*') b *= x;
      else b /= x;
    };
    while (k < s.size() && s[k] != ')') {
      if (s[k] == ' ') {
        k++;
        continue;
      }
      if (s[k] == '(') {
        ll x = dfs(++k, s);
        k++;
        f(a, b, x, op);
      } else if (isdigit(s[k])) {
        ll x = 0;
        while (k < s.size() && isdigit(s[k])) 
          x = x * 10 + (s[k++] - '0');
        f(a, b, x, op);
      } else op = s[k++];
    }

    return a + b;
  }

  int calculate(string &t) {
    string s;
    for (int i = 0; i < t.size(); i++) {
      if (t[i] == ' ') continue;
      if (t[i] == '-' && (s.empty() || s.back() == '(')) s += '0';
      s += t[i];
    }

    int k = 0;
    return dfs(k, s);
  }
};

// class Solution {
//  public:
//   using ll = long long;
//   int calculate(string& t) {
//     string s;
//     for (int i = 0; i < t.size(); i++) {
//       if (t[i] == ' ') continue;
//       if (t[i] == '-' && (s.empty() || s.back() == '(')) s += '0';
//       s += t[i];
//     }
//     auto mp = [](char ch){
//       switch (ch) {
//         case '(': return 0;
//         case '+': case '-': return 1;
//         case '*': case '/': return 2;
//         default: return -1;
//       }
//     };
//     auto calc = [](auto& stk, auto& ops) {
//       ll b = stk.top(); stk.pop();
//       ll a = stk.top(); stk.pop();
//       char op = ops.top(); ops.pop();
//       switch (op) {
//         case '+': stk.push(a + b); break;
//         case '-': stk.push(a - b); break;
//         case '*': stk.push(a * b); break;
//         case '/': stk.push(a / b); break;
//       }
//     };
//     stack<ll> stk;
//     stack<char> ops;
//     for (int i = 0; i < s.size(); i++) {
//       if (s[i] == '(') ops.push('(');
//       else if (isdigit(s[i])) {
//         ll x = 0;
//         int j = i;
//         while (j < s.size() && isdigit(s[j])) x = x * 10 + (s[j++] - '0');
//         stk.push(x);
//         i = j - 1;
//       } else if (s[i] == ')') {
//         while (ops.top() != '(') calc(stk, ops);
//         ops.pop();
//       } else {
//         while (ops.size() && mp(ops.top()) >= mp(s[i])) calc(stk, ops);
//         ops.push(s[i]);
//       }
//     }

//     while (ops.size()) calc(stk, ops);
//     return stk.top();
//   }
// };
// @lc code=end