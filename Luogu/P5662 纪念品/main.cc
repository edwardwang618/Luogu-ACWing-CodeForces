#include <iostream>
#include <cstring>
using namespace std;

const int N = 110, M = 1e4 + 10;
int t, n, m;
int p[N][N], f[M];

int main() {
  scanf("%d%d%d", &t, &n, &m);
  for (int i = 1; i <= t; i++) 
    for (int j = 1; j <= n; j++)
      scanf("%d", &p[i][j]);

  for (int i = 1; i < t; i++) {
    fill(f, f + m + 1, m);
    for (int j = 1; j <= n; j++)
      for (int c = 0; c <= m; c++)
        if (c >= p[i][j] && p[i + 1][j] - p[i][j] > 0) 
          f[c] = max(f[c], f[c - p[i][j]] + p[i + 1][j] - p[i][j]);
    m = f[m];
  }

  printf("%d\n", m);
}