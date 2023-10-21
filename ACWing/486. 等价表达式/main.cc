#include <iostream>
#include <cstring>
#include <stack>
#include <string>
#include <unordered_map>
using namespace std;
using ll = long long;

namespace {

const int N = 30, MOD = 1e9 + 7;
int n;
unordered_map<char, int> prio{{'(', 0}, {'+', 1}, {'-', 1}, {'*', 2}, {'^', 3}};
string s;
string ss[N];
stack<char> ops;
stack<ll> stk;
bool cor[N];

ll pow(ll a, ll b) {
  ll res = 1ll;
  while (b) {
    if (b & 1) res = res * a % MOD;
    a = a * a % MOD;
    b >>= 1ll;
  }
  return ((res % MOD) + MOD) % MOD;
}

void calc(stack<ll> &stk, stack<char> &ops) {
  ll a2 = stk.top(); stk.pop();
  ll a1 = stk.top(); stk.pop();
  char op = ops.top(); ops.pop();
  ll res = 0;
  switch (op) {
    case '+': res = a1 + a2; break;
    case '-': res = a1 - a2; break;
    case '*': res = a1 * a2; break;
    case '^': res = pow(a1, a2);
  }

  res = ((res % MOD) + MOD) % MOD;
  stk.push(res);
}

ll work(string &s, ll a) {
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == ' ') continue;
    else if (s[i] == '(') ops.push('(');
    else if (isdigit(s[i])) {
      ll x = s[i] - '0';
      int j = i + 1;
      while (j < s.size() && isdigit(s[j])) {
        x = x * 10 + s[j] - '0';
        j++;
      }
      i = j - 1;
      stk.push(x);
    } else if (s[i] == 'a') {
      stk.push(a);
    } else if (s[i] == ')') {
      while (ops.top() != '(') calc(stk, ops);
      ops.pop();
    } else if (prio.count(s[i])) {
      while (ops.size() && prio[ops.top()] >= prio[s[i]]) calc(stk, ops);
      ops.push(s[i]);
    }
  }

  while (ops.size()) calc(stk, ops);
  ll res = stk.top(); stk.pop();
  return res;
}

}  // namespace

int main() {
  memset(cor, 1, sizeof cor);
  getline(cin, s);
  scanf("%d\n", &n);
  for (int i = 0; i < n; i++) getline(cin, ss[i]);

  for (ll x = 1; x <= 1000; x++) {
    ll res = work(s, x);
    for (int i = 0; i < n; i++) {
      if (!cor[i]) continue;
      ll resi = work(ss[i], x);
      if (resi != res) cor[i] = false;
    }
  }

  for (int i = 0; i < n; i++) if (cor[i]) putchar('A' + i);
}