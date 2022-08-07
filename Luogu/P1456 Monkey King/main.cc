#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int n, m;
int v[N], d[N], l[N], r[N];
int p[N];

int find(int x) {
  if (p[x] != x) p[x] = find(p[x]);
  return p[x];
}

int merge(int x, int y) {
  if (!x || !y) return x ^ y;
  if (v[x] < v[y]) swap(x, y);
  r[x] = merge(r[x], y);
  if (d[l[x]] < d[r[x]]) swap(l[x], r[x]);
  d[x] = d[r[x]] + 1;
  return x;
}

int main() {
  while (~scanf("%d", &n)) {
    for (int i = 1; i <= n; i++) {
      scanf("%d", &v[i]);
      p[i] = i;
      d[i] = 1;
      l[i] = r[i] = 0;
    }

    scanf("%d", &m);
    while (m--) {
      int x, y;
      scanf("%d%d", &x, &y);
      x = find(x), y = find(y);
      if (x == y) puts("-1");
      else {
        int t = merge(merge(l[x], l[y]), merge(r[x], r[y]));
        l[x] = r[x] = l[y] = r[y] = 0;
        v[x] /= 2, v[y] /= 2;
        t = merge(t, merge(x, y));
        p[x] = p[y] = p[t] = t;
        printf("%d\n", v[t]);
      }
    }
  }
}