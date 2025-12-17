#include <iostream>
#include <stack>
using namespace std;

int n;
string s;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> s;
  n = s.size();
  s = " " + s;

  auto match = [](char a, char b) {
    return a == '(' && b == ')' || a == '[' && b == ']' || a == '{' && b == '}';
  };
  stack<int> stk;
  int res = 0;
  for (int i = 1; i <= n; i++) {
    char ch = s[i];
    if (ch == '(' || ch == '[' || ch == '{')
      stk.push(i);
    else {
      if (stk.empty() || !match(s[stk.top()], ch))
        stk.push(i);
      else {
        stk.pop();
        res = max(res, i - (stk.size() ? stk.top() : 0));
      }
    }
  }
  printf("%d\n", res);
}