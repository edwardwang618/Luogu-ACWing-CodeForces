#include <iostream>
#include <stack>
using namespace std;

const int N = 1e6 + 10, P = 1e4;
char s[N];
stack<long> stk;

int main() {
  scanf("%s", s);
  bool is_mult = false;
  for (int i = 0; s[i]; i++) {
    if (s[i] == '*') is_mult = true;
    else if (s[i] == '+') is_mult = false;
    else {
      int j = i;
      long num = 0;
      while (s[j] && '0' <= s[j] && s[j] <= '9') {
        num = (num * 10 + s[j] - '0') % P;
        j++;
      }
      i = j - 1;

      if (is_mult) {
        long top = stk.top();
        stk.pop();
        stk.push(top * num % P);
      } else stk.push(num);
    }
  }

  long res = 0;
  while (stk.size()) {
    res = (res + stk.top()) % P;
    stk.pop();
  }

  printf("%ld\n", res);
}