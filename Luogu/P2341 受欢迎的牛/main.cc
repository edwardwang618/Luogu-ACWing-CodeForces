#include <iostream>
#include <cstring>
using namespace std;

const int N = 1e4 + 10, M = 5e4 + 10;
int n, m;
int h[N], e[M], ne[M], idx;
int dfn[N], low[N], timestamp;
int stk[N], top;
bool in_stk[N];
int id[N], scc_cnt, sz[N];
int dout[N];

void add(int a, int b) {
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
      sz[scc_cnt]++;
    } while (y != u);
  }
}

int main() {
  memset(h, -1, sizeof h);
  scanf("%d%d", &n, &m);
  while (m--) {
    int a, b;
    scanf("%d%d", &a, &b);
    add(a, b);
  }
  
  for (int i = 1; i <= n; i++)
    if (!dfn[i]) tarjan(i);

  for (int i = 1; i <= n; i++)
    for (int j = h[i]; ~j; j = ne[j])
      if (id[i] != id[e[j]])
        dout[id[i]]++;
  
  int zero = 0, res;
  for (int i = 1; i <= scc_cnt; i++) {
    if (!dout[i]) {
      if (++zero > 1) {
        res = 0;
        break;
      }
      res = sz[i];
    }
  }

  printf("%d\n", res);
}