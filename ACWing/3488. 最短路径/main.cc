#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
using PII = pair<int, int>;

const int N = 110, M = 1010, MOD = 1e5;
int n, m;
int h[N], e[M], ne[M], w[M], idx;
int p[N];
int dist[N];

int find(int x) {
  if (p[x] != x) p[x] = find(p[x]);
  return p[x];
}

void add(int a, int b, int c) {
  e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}

void dfs(int u, int from, int d) {
  dist[u] = d;
  for (int i = h[u]; ~i; i = ne[i]) {
    int v = e[i];
    if (v == from) continue;
    dfs(v, u, (d + w[i]) % MOD);
  }
}

int main() {
  memset(h, -1, sizeof h);
  memset(dist, -1, sizeof dist);
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) p[i] = i;
  for (int i = 1, len = 1; i <= m; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    int pa = find(a), pb = find(b);
    if (pa != pb) {
      add(a, b, len), add(b, a, len);
      p[pa] = pb;
    }
    len = len * 2 % MOD;
  }

  dfs(0, -1, 0);
  for (int i = 1; i < n; i++) printf("%d\n", dist[i]);
}