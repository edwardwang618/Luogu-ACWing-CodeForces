#include <iostream>
using namespace std;

const int N = 1e6 + 10;
int n, m;
int v[N], d[N], l[N], r[N];
int p[N];

int find(int x) {
  if (p[x] != x) p[x] = find(p[x]);
  return p[x];
}

int merge(int x, int y) {
  if (!x || !y) return x ^ y;
  if (v[x] > v[y]) swap(x, y);
  r[x] = merge(r[x], y);
  if (d[l[x]] < d[r[x]]) swap(l[x], r[x]);
  d[x] = d[r[x]] + 1;
  return x;
}

int main() {
  v[0] = 2e9;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &v[i]);
    p[i] = i;
    d[i] = 1;
  }

  scanf("%d", &m);
  while (m--) {
    char op;
    int x, y;
    cin >> op >> x;
    if (op == 'M') {
      cin >> y;
      if (!d[x] || !d[y]) continue;
      x = find(x), y = find(y);
      if (x == y) continue;
      if (v[x] > v[y]) swap(x, y);
      p[y] = x;
      merge(x, y);
    } else {
      if (!d[x]) {
        puts("0");
        continue;
      }
      x = find(x);
      d[x] = 0;
      printf("%d\n", v[x]);
      if (v[l[x]] > v[r[x]]) swap(l[x], r[x]);
      p[x] = p[l[x]] = l[x];
      merge(l[x], r[x]);
    }
  }
}