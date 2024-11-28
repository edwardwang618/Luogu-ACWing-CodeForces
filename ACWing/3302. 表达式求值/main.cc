#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

unordered_map<char, int> mp;
string s;

void cal(stack<int>& stk, stack<char>& ops) {
  int y = stk.top(); stk.pop();
  int x = stk.top(); stk.pop();
  char op = ops.top(); ops.pop();
  switch (op) {
    case '+': stk.push(x + y); break;
    case '-': stk.push(x - y); break;
    case '*': stk.push(x * y); break;
    case '/': stk.push(x / y); break;
  }
}

int main() {
  cin >> s;

  mp['('] = 0;
  mp['+'] = mp['-'] = 1;
  mp['*'] = mp['/'] = 2;

  stack<int> stk;
  stack<char> ops;

  for (int i = 0; i < s.size(); i++) {
    char ch = s[i];
    if (isdigit(ch)) {
      int j = i;
      while (j < s.size() && isdigit(s[j])) j++;
      int x = stoi(s.substr(i, j - i));
      stk.push(x);
      i = j - 1;
    } else if (ch == '(')
      ops.push(ch);
    else if (ch == ')') {
      while (ops.top() != '(') cal(stk, ops);
      ops.pop();
    } else {
      while (ops.size() && mp[ops.top()] >= mp[ch]) cal(stk, ops);
      ops.push(ch);
    }
  }
  while (ops.size()) cal(stk, ops);
  cout << stk.top() << endl;
}