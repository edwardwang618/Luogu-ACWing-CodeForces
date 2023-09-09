#include <iostream>
#include <cmath>
#include <cstring>
#include <queue>
#include <array>
using namespace std;

const int N = 5e5 + 10, M = N * 2;
int n, m;
int h[N], e[M], ne[M], idx;
int dep[N], f[N][30];
bool vis[N];

#define add(a, b) e[idx] = b, ne[idx] = h[a], h[a] = idx++

void bfs() {
  memset(dep, -1, sizeof dep);
  dep[1] = 0;
  queue<int> q;
  q.push(1);
  vis[1] = true;
  while (q.size()) {
    auto u = q.front(); q.pop();
    for (int i = h[u]; ~i; i = ne[i]) {
      int v = e[i];
      if (vis[v]) continue;
      vis[v] = true;
      dep[v] = dep[u] + 1;
      q.push(v);
      f[v][0] = u;
      for (int k = 1; 1 << k <= dep[v]; k++) f[v][k] = f[f[v][k - 1]][k - 1];
    }
  }
}

int lca(int u, int v) {
  if (dep[u] < dep[v]) swap(u, v);

  for (int k = 0, diff = dep[u] - dep[v]; (1 << k) <= diff; k++)
    if (diff >> k & 1) u = f[u][k];

  if (u == v) return u;

  for (int k = log2(dep[u]) + 1; k >= 0; k--)
    if (f[u][k] != f[v][k]) u = f[u][k], v = f[v][k];

  return f[u][0];
}

int main() {
  memset(h, -1, sizeof h);
  scanf("%d%d", &n, &m);
  for (int i = 1; i < n; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    add(a, b), add(b, a);
  }

  bfs();

  while (m--) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    array<int, 3> s = {lca(a, b), lca(b, c), lca(a, c)};
    if (s[0] == s[1]) swap(s[1], s[2]);
    if (dep[s[0]] < dep[s[1]]) swap(s[0], s[1]);

    printf("%d %d\n", s[0], dep[a] + dep[b] + dep[c] - dep[s[0]] - 2 * dep[s[1]]);
  }
}