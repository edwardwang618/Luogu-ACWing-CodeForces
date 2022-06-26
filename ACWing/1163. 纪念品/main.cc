#include <iostream>
#include <cstring>
using namespace std;

const int N = 110, M = 1e4 + 10;
int t, n, m;
int p[N][N], f[N][M];

int main() {
  scanf("%d%d%d", &t, &n, &m);
  for (int i = 1; i <= t; i++) 
    for (int j = 1; j <= n; j++)
      scanf("%d", &p[i][j]);

  int res = m;
  for (int i = 1; i < t; i++) {
    memset(f, 0, sizeof f);
    for (int j = 1; j <= n; j++)
      for (int c = 0; c <= res; c++) {
        f[j][c] = f[j - 1][c];
        if (c >= p[i][j] && p[i + 1][j] - p[i][j] > 0) 
          f[j][c] = max(f[j][c], f[j][c - p[i][j]] + p[i + 1][j] - p[i][j]);
      }
    res += f[n][res];
  }

  printf("%d\n", res);
}