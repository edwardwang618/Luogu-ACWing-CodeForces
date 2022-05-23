#include <iostream>
#include <cstring>
using namespace std;

const int N = 1010;
int n;
bool g[N][N];
int dfn[N], low[N], timestamp;
int stk[N], top;
int id[N], din[N], scc_cnt;
bool in_stk[N];

void tarjan(int u) {
  dfn[u] = low[u] = ++timestamp;
  stk[top++] = u, in_stk[u] = true;
  for (int v = 1; v <= n; v++)
    if (g[u][v]) {
      if (!dfn[v]) {
        tarjan(v);
        low[u] = min(low[u], low[v]);
      } else if (in_stk[v]) low[u] = min(low[u], dfn[v]);
    }
  
  if (dfn[u] == low[u]) {
    int y;
    scc_cnt++;
    do {
      y = stk[--top];
      in_stk[y] = false;
      id[y] = scc_cnt;
    } while (y != u);
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      scanf("%d", &g[i][j]);

  for (int i = 1; i <= n; i++)
    if (!dfn[i])
      tarjan(i);
  
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      if (g[i][j] && id[i] != id[j])
        din[id[j]]++;

  int res = 0;
  for (int i = 1; i <= scc_cnt; i++) 
    if (!din[i]) res++;

  printf("%d\n", res);
}