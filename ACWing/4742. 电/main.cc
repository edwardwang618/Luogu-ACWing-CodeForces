#include <cstring>
#include <iostream>
using namespace std;

const int N = 2e5 + 10, M = N << 1;
int n;
int w[N];
int h[N], e[M], ne[M], idx;
int f[N];

#define add(a, b) e[idx] = b, ne[idx] = h[a], h[a] = idx++

void dfs(int u, int p) {
  if (f[u]) return;
  f[u] = 1;
  for (int i = h[u]; ~i; i = ne[i]) {
    int v = e[i];
    if (v == p || w[u] <= w[v]) continue;
    if (!f[v]) dfs(v, u);
    f[u] += f[v];
  }
}

int main() {
  int T;
  scanf("%d", &T);
  for (int i = 1; i <= T; i++) {
    memset(h, -1, sizeof h);
    idx = 0;
    memset(f, 0, sizeof f);
    scanf("%d", &n);
    for (int j = 1; j <= n; j++) scanf("%d", &w[j]);
    for (int j = 1, a, b; j <= n - 1; j++)
      scanf("%d%d", &a, &b), add(a, b), add(b, a);

    int res = 0;
    for (int i = 1; i <= n; i++) {
      if (!f[i]) dfs(i, i);
      res = max(res, f[i]);
    }

    printf("Case #%d: %d\n", i, res);
  }
}