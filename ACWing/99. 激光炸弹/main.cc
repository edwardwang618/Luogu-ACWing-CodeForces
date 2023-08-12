#include <iostream>
using namespace std;

const int N = 5010;
int g[N][N];
int m, n;

int main() {
  int N, r;
  scanf("%d%d", &N, &r);
  r = min(r, 5001);
  n = m = r;
  for (int i = 0, x, y, w; i < N; i++) {
    scanf("%d%d%d", &x, &y, &w);
    x++, y++;
    g[x][y] += w;
    n = max(n, x), m = max(m, y);
  }

  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      g[i][j] += g[i - 1][j] + g[i][j - 1] - g[i - 1][j - 1];

  int res = 0;
  for (int i = r; i <= n; i++)
    for (int j = r; j <= m; j++)
      res = max(res, g[i][j] - g[i - r][j] - g[i][j - r] + g[i - r][j - r]);
  printf("%d\n", res);
}