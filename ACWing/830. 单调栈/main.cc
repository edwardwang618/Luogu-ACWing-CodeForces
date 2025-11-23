#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int n, stk[N], top;

int main() {
  scanf("%d", &n);
  int x;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &x);
    if (!top) printf("-1 ");
    else {
      while (top && stk[top - 1] >= x) top--;
      printf("%d ",  top ? stk[top - 1] : -1);
    }
    stk[top++] = x;
  }
}