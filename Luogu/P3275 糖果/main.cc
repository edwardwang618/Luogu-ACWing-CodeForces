#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int N = 1e5 + 10, M = 4e5 + 10;
int n, m;
int h[N], hs[N], e[M], ne[M], w[M], idx;
int dfn[N], low[N], timestamp;
int stk[N], top;
bool in_stk[N];
int id[N], scc_cnt, sz[N];
int ind[N];
int dist[N];
queue<int> q;

void add(int a, int b, int c, int h[]) {
  e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}

void tarjan(int u) {
  dfn[u] = low[u] = ++timestamp;
  stk[top++] = u, in_stk[u] = true;
  for (int i = h[u]; ~i; i = ne[i]) {
    if (w[i]) continue;
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
      sz[scc_cnt]++;
    } while (y != u);
  }
}

int main() {
  memset(h, -1, sizeof h);
  memset(hs, -1, sizeof hs);
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) add(0, i, 0, h);
  while (m--) {
    int op, a, b;
    scanf("%d%d%d", &op, &a, &b);
    if (a == b) {
      if (op == 2 || op == 4) {
        puts("-1");
        return 0;
      }
      continue;
    }
    if (op == 1) add(a, b, 0, h), add(b, a, 0, h);
    else if (op == 2) add(a, b, 1, h);
    else if (op == 3) add(b, a, 0, h);
    else if (op == 4) add(b, a, 1, h);
    else add(a, b, 0, h);
  }

  for (int i = 1; i <= n; i++)
    if (!dfn[i])
      tarjan(i);

  for (int i = 1; i <= n; i++)
    for (int j = h[i]; ~j; j = ne[j]) {
      int x = id[i], y = id[e[j]];
      if (x != y) {
        ind[y]++;
        add(x, y, w[j], hs);
      } else if (w[j]) {
        puts("-1");
        return 0;
      }
    }

  for (int i = 1; i <= scc_cnt; i++)
    if (!ind[i]) {
      q.push(i);
      dist[i] = 1;
    }

  n = 0;
  while (q.size()) {
    n++;
    int t = q.front(); q.pop();
    for (int i = hs[t]; ~i; i = ne[i]) {
      int v = e[i];
      dist[v] = max(dist[v], dist[t] + w[i]);
      ind[v]--;
      if (!ind[v]) q.push(v);
    }
  }

  if (n < scc_cnt) puts("-1");
  else {
    long res = 0;
    for (int i = 1; i <= scc_cnt; i++) res += (long) sz[i] * dist[i];
    printf("%ld\n", res);
  }
  return 0;
}