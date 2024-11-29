#include <iostream>
#include <stack>
#include <unordered_set>
using namespace std;
using ll = long long;

string s;

void calc(auto& stk, char op) {
  ll x;
  ll b = stk.top(); stk.pop();
  ll a = stk.top(); stk.pop();
  switch (op) {
    case '+': x = a + b; break;
    case '-': x = a - b; break;
    case '*': x = a * b; break;
    case '/': x = a / b;
  }
  stk.push(x);
}

int main() {
  getline(cin, s);
  ll x = 0;
  stack<ll> stk;
  unordered_set<char> ops{'+', '-', '*', '/'};
  for (int i = 0; i < s.size(); i++) {
    if (isdigit(s[i])) {
      int j = i;
      while (j < s.size() && isdigit(s[j])) j++;
      stk.push(stoll(s.substr(i, j - i)));
      i = j;
    } else if (ops.count(s[i])) calc(stk, s[i]);
  }
  printf("%lld\n", stk.top());
}