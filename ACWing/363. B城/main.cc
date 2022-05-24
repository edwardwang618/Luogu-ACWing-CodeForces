#include <iostream>
#include <cstring>
using namespace std;

const int N = 1e5 + 10, M = 1e6 + 10;
int n, m;
int h[N], e[M], ne[M], idx;
int dfn[N], low[N], timestamp;
int cnt[N];
long res[N];

void add(int a, int b) {
  e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void tarjan(int u, int from) {
  dfn[u] = low[u] = ++timestamp;
  cnt[u] = 1;

  int sum = 0;
  for (int i = h[u]; ~i; i = ne[i]) {
    int v = e[i];
    if (!dfn[v]) {
      tarjan(v, u);
      cnt[u] += cnt[v];
      low[u] = min(low[u], low[v]);
      if (low[v] >= dfn[u]) {
        res[u] += (long) cnt[v] * (n - cnt[v]);
        sum += cnt[v];
      }
    } else if (v != from) low[u] = min(low[u], dfn[v]);
  }

  res[u] += (long) (n - 1 - sum) * (1 + sum) + (n - 1);
}

int main() {
  scanf("%d%d", &n, &m);
  memset(h, -1, sizeof h);
  while (m--) {
    int a, b;
    scanf("%d%d", &a, &b);
    add(a, b), add(b, a);
  }

  tarjan(1, 1);
  for (int i = 1; i <= n; i++)
    printf("%ld\n", res[i]);
}