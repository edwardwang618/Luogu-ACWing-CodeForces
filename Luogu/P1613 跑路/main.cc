#include <iostream>
#include <cstring>
using namespace std;

const int N = 60, K = 65;
int n, m;
int g[N][N], dist[N];
bool vis[N];
bool f[N][N][K];

int dijkstra() {
  memset(dist, 0x3f, sizeof dist);
  memset(vis, 0, sizeof vis);

  dist[1] = 0;
  for (int i = 1; i <= n; i++) {
    int t = -1;
    for (int j = 1; j <= n; j++)
      if (!vis[j] && (t == -1 || dist[j] < dist[t])) t = j;

    if (t == n) break;
    vis[t] = true;
    for (int j = 1; j <= n; j++)
      if (!vis[j]) dist[j] = min(dist[j], dist[t] + g[t][j]);
  }

  return dist[n];
}

int main() {
  memset(g, 0x3f, sizeof g);

  scanf("%d%d", &n, &m);
  while (m--) {
    int a, b;
    scanf("%d%d", &a, &b);
    f[a][b][0] = true;
    g[a][b] = 1;
  }

  for (int i = 1; i <= n; i++) g[i][i] = 0;

  for (int l = 1; l < K; l++)
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
        for (int k = 1; k <= n; k++)
          if (f[i][k][l - 1] && f[k][j][l - 1]) {
            f[i][j][l] = true;
            if (i != j) g[i][j] = 1;
          }

  printf("%d\n", dijkstra());
}
