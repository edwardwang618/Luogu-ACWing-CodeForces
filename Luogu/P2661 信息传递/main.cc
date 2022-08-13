#include <iostream>
using namespace std;

const int N = 2e5 + 10;
int n, p[N], d[N], res = 2e9;

int find(int x) {
  if (p[x] != x) {
    int px = find(p[x]);
    d[x] += d[p[x]];
    p[x] = px;
  }
  return p[x];
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) p[i] = i;
  for (int i = 1; i <= n; i++) {
    int x;
    scanf("%d", &x);
    if (find(x) == i) res = min(res, d[x] + 1);
    else p[i] = x, d[i] = 1;
  }

  printf("%d\n", res);
}