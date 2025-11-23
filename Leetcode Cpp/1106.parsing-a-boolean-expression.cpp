/*
 * @lc app=leetcode id=1106 lang=cpp
 *
 * [1106] Parsing A Boolean Expression
 */

// @lc code=start
// class Solution {
//  public:
//   bool dfs(int &k, string& s) {
//     if (s[k] == 't') {
//       k++;
//       return true;
//     }
//     if (s[k] == 'f') {
//       k++;
//       return false;
//     }
//     char op = s[k];
//     k += 2;

//     bool res = op == '&';
//     while (s[k] != ')') {
//       if (s[k] == ',') k++;
//       else {
//         bool t = dfs(k, s);
//         if (op == '&') res &= t;
//         else res |= t;
//       }
//     }

//     k++;
//     if (op == '!') res = !res;
//     return res;
//   }

//   bool parseBoolExpr(string e) {
//     int k = 0;
//     return dfs(k, e);
//   }
// };

class Solution {
 public:
  bool parseBoolExpr(string e) {
    stack<char> ops, stk;
    for (int i = 0; i < e.size(); i++) {
      char ch = e[i];
      if (ch == ',') continue;
      if (ch == '|' || ch == '&' || ch == '!') ops.push(ch);
      else if (ch == '(' || ch == 't' || ch == 'f') stk.push(ch);
      else {
        char op = ops.top(); ops.pop();
        char x = stk.top(); stk.pop();
        bool cur = x == 't';
        if (op == '!') {
          // pop (
          stk.pop();
          stk.push(cur ? 'f' : 't');
        } else {
          while (stk.top() != '(') {
            op == '&' ? cur &= stk.top() == 't' : cur |= stk.top() == 't';
            stk.pop();
          }

          stk.pop();
          stk.push(cur ? 't' : 'f');
        }
      }
    }

    return stk.top() == 't';
  }
};
// @lc code=end
