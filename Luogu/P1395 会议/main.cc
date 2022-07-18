#include <iostream>
#include <cstring>
using namespace std;

const int N = 5e4 + 10, M = N << 1;
int n;
int h[N], e[M], ne[M], idx;
int sz[N], d[N];
int x, y;

void add(int a, int b) {
  e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int dfs1(int u, int from, int dist) {
  sz[u] = 1;
  d[1] += dist;
  for (int i = h[u]; ~i; i = ne[i]) {
    int v = e[i];
    if (v != from) sz[u] += dfs1(v, u, dist + 1);
  }
  return sz[u];
}

void dfs2(int u, int from) {
  if (~from) {
    d[u] = d[from] + n - 2 * sz[u];
    if (d[u] < y) {
      y = d[u];
      x = u;
    } else if (d[u] == y) x = min(x, u);
  }

  for (int i = h[u]; ~i; i = ne[i]) {
    int v = e[i];
    if (v != from) dfs2(v, u);
  }
}

int main() {
  memset(h, -1, sizeof h);
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    add(a, b), add(b, a);
  }

  dfs1(1, -1, 0);
  x = 1, y = d[1];
  dfs2(1, -1);
  printf("%d %d\n", x, y);
}