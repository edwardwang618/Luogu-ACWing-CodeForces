#include <algorithm>
#include <iostream>
using namespace std;

const int N = 2e5 + 10;
int n, d;
struct P {
  int a, b;
} p[N];

int main() {
  scanf("%d%d", &n, &d);
  for (int i = 1; i <= n; i++) scanf("%d%d", &p[i].a, &p[i].b);
  sort(p + 1, p + 1 + n, [](auto& p1, auto& p2) { return p1.a < p2.a; });
  int res = 0;
  for (int i = 1, j = 0, maxb = 0; i <= n; i++) {
    while (p[i].a - p[j + 1].a >= d) maxb = max(maxb, p[++j].b);
    if (j) res = max(res, maxb + p[i].b);
  }
  printf("%d\n", res);
}