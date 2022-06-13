#include <iostream>
#include <cstring>
using namespace std;

const int N = 110, INF = 0x3f3f3f3f;
int n, m;
int g[N][N], d[N][N];

int floyd() {
  int res = INF;
  for (int k = 1; k <= n; k++) {
    for (int i = 1; i < k; i++)
      for (int j = i + 1; j < k; j++)
        if (d[i][j] < INF && g[j][k] < INF && g[k][i] < INF)
          res = min(res, d[i][j] + g[j][k] + g[k][i]);
    for (int i = 1; i <= n; i++)
      for (int j = i + 1; j <= n; j++)
        d[i][j] = d[j][i] = min(d[i][j], d[i][k] + d[k][j]);
  }

  return res;
}

int main() {
  memset(g, 0x3f, sizeof g);
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) g[i][i] = 0;
  while (m--) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    g[a][b] = g[b][a] = min(g[a][b], c);
  }

  memcpy(d, g, sizeof g);

  int res = floyd();
  res < INF ? printf("%d\n", res) : puts("No solution.");
}