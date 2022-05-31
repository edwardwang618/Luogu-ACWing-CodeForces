#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int n, a[N];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  int l = 1, r = n, ml = a[1], mr = a[n];
  int res = 0;
  while (l < r) {
    if (a[l] <= a[r]) {
      res += max(0, min(ml, mr) - a[++l]);
      ml = max(ml, a[l]);
    } else {
      res += max(0, min(ml, mr) - a[--r]);
      mr = max(mr, a[r]);
    }
  }

  printf("%d\n", res);
}