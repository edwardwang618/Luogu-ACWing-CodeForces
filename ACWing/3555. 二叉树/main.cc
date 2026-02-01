#include <cstring>
#include <iostream>
using namespace std;

const int N = 1010, LOG = 10;
int n, m;
int L[N], R[N];
int f[LOG][N], dep[N];

void dfs(int u, int fa, int d) {
  if (u == -1)
    return;
  dep[u] = d;
  f[0][u] = fa;
  for (int j = 1; j < LOG; j++)
    if (f[j - 1][u] != -1)
      f[j][u] = f[j - 1][f[j - 1][u]];
  dfs(L[u], u, d + 1);
  dfs(R[u], u, d + 1);
}

int lca(int x, int y) {
  if (dep[x] > dep[y])
    swap(x, y);

  int diff = dep[y] - dep[x];
  for (int i = 0; (1 << i) <= diff; i++)
    if (diff >> i & 1)
      y = f[i][y];

  if (x == y)
    return x;

  for (int i = LOG - 1; i >= 0; i--)
    if (f[i][x] != f[i][y])
      x = f[i][x], y = f[i][y];

  return f[0][x];
}

int main() {
  int T;
  scanf("%d", &T);

  while (T--) {
    scanf("%d%d", &n, &m);
    memset(f, -1, sizeof f);

    for (int i = 1; i <= n; i++)
      scanf("%d%d", &L[i], &R[i]);

    dfs(1, -1, 0);

    while (m--) {
      int x, y;
      scanf("%d%d", &x, &y);
      int lc = lca(x, y);
      printf("%d\n", dep[x] + dep[y] - 2 * dep[lc]);
    }
  }
}