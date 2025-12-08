#include <iostream>
#include <cstring>
using namespace std;

const int N = 510, INF = 0x3f3f3f3f;
int n, m;
int g[N][N], dist[N];
bool vis[N];

int dijkstra() {
  memset(dist, 0x3f, sizeof dist);
  dist[1] = 0;
  for (int i = 1; i <= n; i++) {
    int u = -1;
    for (int i = 1; i <= n; i++) 
      if (!vis[i] && (!~u || dist[i] < dist[u])) u = i;
    
    if (u == n || dist[u] == INF) break;

    vis[u] = true;
    for (int v = 1; v <= n; v++)
      if (!vis[v]) dist[v] = min(dist[v], dist[u] + g[u][v]);
  }

  return dist[n] == INF ? -1 : dist[n];
}

int main() {
  scanf("%d%d", &n, &m);
  memset(g, 0x3f, sizeof g);
  for (int i = 1; i <= n; i++) g[i][i] = 0;
  while (m--) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    if (a == b) continue;
    g[a][b] = min(g[a][b], c);
  }

  printf("%d\n", dijkstra());
}