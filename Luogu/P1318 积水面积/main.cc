#include <iostream>
#define x first
#define y second
using namespace std;
using PII = pair<int, int>;

const int N = 10010;
int n, top;
PII stk[N];

int main() {
  scanf("%d", &n);
  int res = 0;
  for (int i = 0; i < n; i++) {
    int c;
    scanf("%d", &c);
    while (top && stk[top - 1].y <= c) {
      int h = stk[--top].y;
      if (!top) break;
      res += (min(stk[top - 1].y, c) - h) * (i - stk[top - 1].x - 1);
    }
    stk[top++] = {i, c};
  }

  printf("%d\n", res);
}