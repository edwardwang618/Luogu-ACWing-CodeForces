#include <iostream>
#include <cstring>
using namespace std;

const int N = 1e4 + 10, M = 2e5 + 10;
int n, m, c[N];
int h[N], hs[N], e[M], ne[M], idx;
int dfn[N], low[N], timestamp;
int stk[N], top, scc_cnt;
bool in_stk[N];
int id[N], sum[N], f[N];

void add(int a, int b, int h[]) {
  e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void tarjan(int u) {
  dfn[u] = low[u] = ++timestamp;
  stk[top++] = u, in_stk[u] = true;

  for (int i = h[u]; ~i; i = ne[i]) {
    int v = e[i];
    if (!dfn[v]) {
      tarjan(v);
      low[u] = min(low[u], low[v]);
    } else if (in_stk[v]) low[u] = min(low[u], dfn[v]);
  }

  if (dfn[u] == low[u]) {
    scc_cnt++;
    int y;
    do {
      y = stk[--top];
      in_stk[y] = false;
      id[y] = scc_cnt;
      sum[scc_cnt] += c[y];
    } while (y != u);
  }
}

int main() {
  memset(h, -1, sizeof h);
  memset(hs, -1, sizeof hs);

  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &c[i]);
  for (int i = 1; i <= m; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    add(a, b, h);
  }

  for (int i = 1; i <= n; i++)
    if (!dfn[i]) tarjan(i);

  for (int i = 1; i <= n; i++)
    for (int j = h[i]; ~j; j = ne[j])
      if (id[i] != id[e[j]])
        add(id[i], id[e[j]], hs);

  int res = 0;
  for (int i = 1; i <= scc_cnt; i++) {
    int t = 0;
    for (int j = hs[i]; ~j; j = ne[j])
      t = max(t, f[e[j]]);
    f[i] = sum[i] + t;
    res = max(res, f[i]);
  }

  printf("%d\n", res);
}