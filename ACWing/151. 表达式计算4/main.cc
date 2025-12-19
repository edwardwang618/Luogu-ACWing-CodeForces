#include <iostream>
#include <stack>
using namespace std;
using ll = long long;

string s;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> s;
  s = '(' + s + ')';
  int l = 0, r = 0;
  for (char ch : s) {
    if (ch == '(') l++;
    else if (ch == ')') r++;
  }
  if (l > r) s = s + string(l - r, ')');
  if (l < r) s = string(r - l, '(') + s;

  auto f = [](char op) {
    switch (op) {
      case '(': return 0;
      case '+': case '-': return 1;
      case '*': case '/': return 2;
      case '^': return 3;
      default: return -1;
    }
  };

  stack<ll> stk;
  stack<char> ops;

  auto calc = [](auto &stk, auto &ops) {
    char op = ops.top(); ops.pop();
    if (op == '(' || op == ')') return;
    ll y = stk.top(); stk.pop();
    ll x = stk.top(); stk.pop();
    if (op == '+') stk.push(x + y);
    else if (op == '-') stk.push(x - y);
    else if (op == '*') stk.push(x * y);
    else if (op == '/') stk.push(x / y);
    else {
      if (!x) stk.push(0);
      else {
        ll res = 1;
        while (y) {
          if (y & 1) res *= x;
          y >>= 1;
          x *= x;
        }
        stk.push(res);
      }
    }
  };

  for (int i = 0; i < s.size(); i++) {
    char ch = s[i];
    if (isdigit(ch)) {
      int j = i;
      ll x = 0;
      while (isdigit(s[j]))
        x = x * 10 + s[j++] - '0';
      i = j - 1;
      stk.push(x);
    } else if (ch == '(') ops.push('(');
    else if (ch == ')') {
      while (ops.top() != '(') calc(stk, ops);
      ops.pop();
    } else if (ch == '-' && i && !isdigit(s[i - 1]) && s[i - 1] != ')') {
      if (s[i + 1] == '(') {
        stk.push(-1);
        ops.push('*');
      } else {
        int j = i + 1;
        ll x = 0;
        while (isdigit(s[j])) x = x * 10 + s[j++] - '0';
        stk.push(-x);
        i = j - 1;
      }
    } else {
      while (f(ops.top()) >= f(ch)) calc(stk, ops);
      ops.push(ch);
    }
  }
  printf("%lld\n", stk.top());
}