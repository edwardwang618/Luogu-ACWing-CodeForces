#include <iostream>
#include <cstring>
using namespace std;

const int N = 1010, M = 2e5 + 10, INF = 0x3f3f3f3f;
int n, m, K;
int a[N], dist[N];
int g[N][N];
bool vis[N];

bool dijkstra() {
  memset(dist, 0x3f, sizeof dist);
  memset(vis, 0, sizeof vis);
  dist[a[1]] = 0;
  for (int i = 1; i <= n; i++) {
    int t = a[i];
    for (int j = 1; j <= n; j++)
      if (!vis[j] && dist[j] < dist[t]) return false;

    vis[t] = true;
    for (int j = 1; j <= n; j++)
      dist[j] = min(dist[j], dist[t] + g[t][j]);
  }

  return true;
}

int main() {
  memset(g, 0x3f, sizeof g);
  scanf("%d%d", &n, &m);

  for (int i = 1; i <= n; i++) g[i][i] = 0;
  for (int i = 1; i <= m; i++) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    g[a][b] = g[b][a] = min(g[a][b], c);
  }

  scanf("%d", &K);
  while (K--) {
    for (int i = 1; i <= n; i++)
      scanf("%d", &a[i]);
    
    dijkstra() ? puts("Yes") : puts("No");
  }
}