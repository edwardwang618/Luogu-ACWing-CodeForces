#include <iostream>
using namespace std;

const int N = 1e6 + 10;
char s[N];
int stk[N], top;
int maxl, cnt;

int main() {
  scanf("%s", s);
  for (int i = 0; s[i]; i++) {
    if (s[i] == '(') stk[top++] = i;
    else {
      if (!top || s[stk[top - 1]] == ')') stk[top++] = i;
      else {
        top--;
        int l = top ? stk[top - 1] : -1;
        if (i - l > maxl) maxl = i - l, cnt = 1;
        else if (i - l == maxl) cnt++;
      }
    }
  }

  if (!maxl) cnt = 1;
  printf("%d %d\n", maxl, cnt);
}