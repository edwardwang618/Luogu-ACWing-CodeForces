#include <iostream>
#include <cstring>
using namespace std;

const int N = 1010, M = 210;
int n, m;
int f[N][M][M], g[M][M], p[N];

int main() {
  scanf("%d%d", &m, &n);
  for (int i = 1; i <= m; i++)
    for (int j = 1; j <= m; j++) scanf("%d", &g[i][j]);
  for (int i = 1; i <= n; i++) scanf("%d", &p[i]);

  memset(f, 0x3f, sizeof f);
  p[0] = 3;
  f[0][1][2] = 0;
  for (int i = 0; i < n; i++)
    for (int x = 1; x <= m; x++)
      for (int y = 1; y <= m; y++) {
        int z = p[i], u = p[i + 1], v = f[i][x][y];
        if (x == y || x == z || y == z) continue;
        f[i + 1][x][y] = min(f[i + 1][x][y], v + g[z][u]);
        f[i + 1][z][y] = min(f[i + 1][z][y], v + g[x][u]);
        f[i + 1][x][z] = min(f[i + 1][x][z], v + g[y][u]);
      }

  int res = 0x3f3f3f3f;
  for (int x = 1; x <= m; x++)
    for (int y = 1; y <= m; y++) {
      int z = p[n];
      if (x == y || x == z || y == z) continue;
      res = min(res, f[n][x][y]);
    }

  printf("%d\n", res);
}