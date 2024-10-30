#include <iostream>
using namespace std;

const int N = 60, M = 15, MOD = 1e9 + 7;
int n, m, k;
int a[N][N];
int f[N][N][M][M];

#define add(a, b) ((a + b) % MOD)

int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      scanf("%d", &a[i][j]);
      a[i][j]++;
    }
  f[1][1][0][0] = 1;
  f[1][1][1][a[1][1]] = 1;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      for (int c = 0; c <= k; c++)
        for (int v = 0; v <= M; v++) {
          int& x = f[i][j][c][v];
          x = add(x, f[i - 1][j][c][v]);
          x = add(x, f[i][j - 1][c][v]);
          if (c && v == a[i][j])
            for (int s = 0; s < a[i][j]; s++) {
              x = add(x, f[i - 1][j][c - 1][s]);
              x = add(x, f[i][j - 1][c - 1][s]);
            }
        }
  int res = 0;
  for (int i = 1; i <= M; i++) res = add(res, f[n][m][k][i]);
  printf("%d\n", res);
}
