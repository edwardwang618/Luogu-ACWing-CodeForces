#include <iostream>
using namespace std;

const int N = 1e6 + 10;
char s[N], stk[N];
int top;

int main() {
  scanf("%s", s);

  int res = 0;
  for (int i = 0; s[i]; i++)
    if (s[i] == '(') stk[top++] = '(';
    else if (top && stk[top - 1] == '(') top--, res += 2;
  
  printf("%d\n", res);
}