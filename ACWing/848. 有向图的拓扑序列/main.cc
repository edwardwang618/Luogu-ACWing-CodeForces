#include <iostream>
#include <cstring>
using namespace std;

const int N = 1e5 + 10;
int n, m;
int h[N], e[N], ne[N], idx;
int ind[N];
int q[N], hh, tt;

void add(int a, int b) {
  e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

bool bfs() {
  for (int i = 1; i <= n; i++) if (!ind[i]) q[tt++] = i;
  while (hh != tt) {
    int u = q[hh++];
    for (int j = h[u]; ~j; j = ne[j]) {
      int v = e[j];
      if (u == v) return false;
      if (!--ind[v]) q[tt++] = v;
    }
  }

  return tt == n;
}

int main() {
  scanf("%d%d", &n, &m);
  memset(h, -1, sizeof h);
  for (int i = 1; i <= m; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    add(a, b);
    ind[b]++;
  }

  if (bfs())
    for (int i = 0; i < n; i++) printf("%d ", q[i]);
  else puts("-1");
}