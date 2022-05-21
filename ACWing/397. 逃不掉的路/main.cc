#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

const int N = 1e5 + 10, M = 4e5 + 10;
int n, m, s;
int h[N], h2[N], e[M << 1], ne[M << 1], idx;
int dfn[N], low[N], timestamp;
int stk[N], top;
int id[N], dcc_cnt;
int dep[N], f[N][20];
int q[N];

void add(int a, int b, int h[]) {
  e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void tarjan(int u, int from) {
  dfn[u] = low[u] = ++timestamp;
  stk[top++] = u;
  for (int i = h[u]; ~i; i = ne[i]) {
    int v = e[i];
    if (!dfn[v]) {
      tarjan(v, u);
      low[u] = min(low[u], low[v]);
    } else if (v != from) low[u] = min(low[u], low[v]);
  }

  if (dfn[u] == low[u]) {
    dcc_cnt++;
    int y;
    do {
      y = stk[--top];
      id[y] = dcc_cnt;
    } while (y != u);
  }
}

void bfs(int u) {
  memset(dep, -1, sizeof dep);
  int hh = 0, tt = 0;
  q[tt++] = u;
  dep[u] = 0;
  while (hh < tt) {
    int t = q[hh++];
    for (int i = h2[t]; ~i; i = ne[i]) {
      int v = e[i];
      if (~dep[v]) continue;
      dep[v] = dep[t] + 1;
      f[v][0] = t;
      for (int k = 1; k <= log2(dep[v]); k++) 
        f[v][k] = f[f[v][k - 1]][k - 1];
      
      q[tt++] = v;
    }
  }
}

int lca(int a, int b) {
  if (dep[a] < dep[b]) swap(a, b);
  for (int k = 0, diff = dep[a] - dep[b]; 1 << k <= diff; k++)
    if (diff >> k & 1) a = f[a][k];
  
  if (a == b) return a;
  for (int k = log2(dep[a]); k >= 0; k--)
    if (f[a][k] != f[b][k])
      a = f[a][k], b = f[b][k];
    
  return f[a][0];
}

int main() {
  memset(h, -1, sizeof h);
  memset(h2, -1, sizeof h2);
  
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    add(a, b, h), add(b, a, h);
  }

  tarjan(1, -1);

  for (int i = 1; i <= n; i++)
    for (int j = h[i]; ~j; j = ne[j]) {
      int v = e[j];
      int a = id[i], b = id[v];
      if (a != b) add(a, b, h2), add(b, a, h2);
    }

  bfs(1);

  scanf("%d", &s);
  while (s--) {
    int a, b;
    scanf("%d%d", &a, &b);
    a = id[a], b = id[b];
    int p = lca(a, b);
    printf("%d\n", dep[a] + dep[b] - 2 * dep[p]);
  }
}