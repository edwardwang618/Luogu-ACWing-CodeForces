#include <iostream>
#include <cstring>
using namespace std;

const int N = 2e5 + 10, M = 1e6 + 10;
int n;
int h[N], e[M], ne[M], idx;
int dfn[N], low[N], timestamp;
int a, b;
bool cut[N];

void add(int a, int b) {
  e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void tarjan(int u, int from) {
  dfn[u] = low[u] = ++timestamp;
  for (int i = h[u]; ~i; i = ne[i]) {
    int v = e[i];
    if (!dfn[v]) {
      tarjan(v, u);
      low[u] = min(low[u], low[v]);
      if (low[v] >= dfn[u] && u != from)
        if(dfn[b] >= dfn[v]) cut[u] = true;
    } else if (v != from) low[u] = min(low[u], dfn[v]);
  }
}

int main() {
  memset(h, -1, sizeof h);
  scanf("%d", &n);
  while (cin >> a >> b, a != 0)
    add(a, b), add(b, a);

  scanf("%d%d", &a, &b);
  tarjan(a, a);

  for (int i = 1; i <= n; i++)
    if (cut[i]) {
      printf("%d\n", i);
      return 0;
    }

  puts("No solution");
}