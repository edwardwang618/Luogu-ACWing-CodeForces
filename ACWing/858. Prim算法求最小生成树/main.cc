#include <iostream>
#include <cstring>
using namespace std;

const int N = 510, M = 1e5 + 10, INF = 0x3f3f3f3f;
int n, m;
int g[N][N], dist[N];
bool vis[N];

int prim() {
  memset(dist, 0x3f, sizeof dist);
  int res = 0;
  for (int i = 1; i <= n; i++) {
    int u = -1;
    for (int v = 1; v <= n; v++)
      if (!vis[v] && (!~u || dist[u] > dist[v])) u = v;
    
    if (i > 1) { 
      if (dist[u] == INF) return INF;
      else res += dist[u];
    }

    vis[u] = true;
    for (int v = 1; v <= n; v++)
      if (!vis[v]) dist[v] = min(dist[v], g[u][v]);
  }

  return res;
}

int main() {
  scanf("%d%d", &n, &m);
  memset(g, 0x3f, sizeof g);
  while (m--) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    if (a == b) continue;
    g[a][b] = g[b][a] = min(g[a][b], c);
  }

  int res = prim();
  res != INF ? printf("%d\n", res) : puts("impossible");
}