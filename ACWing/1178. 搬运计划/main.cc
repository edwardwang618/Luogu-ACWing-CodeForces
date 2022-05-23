#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

const int N = 5e5 + 10;
int n, m, S, P;
int h[N], e[N], ne[N], idx;
int money[N], sum_money[N], f[N];;
bool has_bar[N];
int dfn[N], low[N], timestamp;
int stk[N], top;
bool in_stk[N];
int id[N], scc_cnt;

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
      sum_money[scc_cnt] += money[y];
    } while (y != u);
  }
}

int main() {
  memset(h, -1, sizeof h);
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    add(a, b);
  }

  for (int i = 1; i <= n; i++)
    scanf("%d", &money[i]);

  scanf("%d%d", &S, &P);
  tarjan(S);
  while (P--) {
    int x;
    scanf("%d", &x);
    has_bar[id[x]] = true;
  }

  vector<vector<bool>> g(scc_cnt + 1, vector<bool>(scc_cnt + 1));
  for (int i = 1; i <= n; i++)
    for (int j = h[i]; ~j; j = ne[j]) {
      int v = e[j];
      g[id[i]][id[v]] = true;
    }

  for (int i = scc_cnt; i; i--) {
    f[i] = sum_money[i];
    int t = 0;
    for (int j = i + 1; j <= scc_cnt; j++)
      if (g[j][i]) t = max(t, f[j]);
    f[i] += t;
  }

  int res = 0;
  for (int i = 1; i <= scc_cnt; i++)
    if (has_bar[i]) res = max(res, f[i]);

  printf("%d\n", res);
}