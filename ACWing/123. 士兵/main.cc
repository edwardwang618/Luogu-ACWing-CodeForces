#include <iostream>
#include <algorithm>
using namespace std;

const int N = 10010;
int n;
int x[N], y[N];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d%d", &x[i], &y[i]);
  int res = 0;
  sort(y + 1, y + 1 + n);
  int ymed = y[n + 1 >> 1];
  for (int i = 1; i <= n; i++) res += abs(y[i] - ymed);
  sort(x + 1, x + 1 + n);
  for (int i = 1; i <= n; i++) x[i] -= i - 1;
  sort(x + 1, x + 1 + n);
  int xmed = x[n + 1 >> 1];
  for (int i = 1; i <= n; i++) res += abs(x[i] - xmed);
  printf("%d\n", res);
}