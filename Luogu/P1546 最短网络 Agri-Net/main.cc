#include <iostream>
#include <cstring>
using namespace std;

const int N = 110, INF = 0x3f3f3f3f;
int n;
int g[N][N];
int dist[N];
bool vis[N];

int prim() {
  memset(dist, 0x3f, sizeof dist);
  dist[1] = 0;
  int res = 0;
  for (int i = 1; i <= n; i++) {
    int u = -1;
    for (int j = 1; j <= n; j++)
      if (!vis[j] && (!~u || dist[j] < dist[u])) u = j;

    if (dist[u] == INF) return -1;
    vis[u] = true;
    res += dist[u];
    for (int j = 1; j <= n; j++)
      if (!vis[j]) dist[j] = min(dist[j], g[u][j]);
  }

  return res;
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) scanf("%d", &g[i][j]);

  printf("%d\n", prim());
}