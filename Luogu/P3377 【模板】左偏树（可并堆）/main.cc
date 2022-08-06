#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int n, m;
int v[N], d[N], l[N], r[N];
int p[N];
bool del[N];

bool cmp(int x, int y) {
  if (v[x] != v[y]) return v[x] < v[y];
  return x < y;
}

int find(int x) {
  if (p[x] != x) p[x] = find(p[x]);
  return p[x];
}

int merge(int x, int y) {
  if (!x || !y) return x ^ y;
  if (!cmp(x, y)) swap(x, y);
  r[x] = merge(r[x], y);
  if (d[r[x]] > d[l[x]]) swap(l[x], r[x]);
  d[x] = d[r[x]] + 1;
  return x;
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    p[i] = i;
    d[i] = 1;
    scanf("%d", &v[i]);
  }

  while (m--) {
    int t, x, y;
    scanf("%d%d", &t, &x);
    if (t == 1) {
      scanf("%d", &y);
      if (del[x] || del[y]) continue;
      x = find(x), y = find(y);
      if (x == y) continue;
      if (!cmp(x, y)) swap(x, y);
      p[y] = x;
      merge(x, y);
    } else {
      if (del[x]) {
        puts("-1");
        continue;
      }
      x = find(x);
      printf("%d\n", v[x]);
      del[x] = true;
      if (!l[x]) continue;
      if (r[x] && !cmp(l[x], r[x])) swap(l[x], r[x]);
      p[x] = p[l[x]] = l[x];
      merge(l[x], r[x]);
    }
  }
}