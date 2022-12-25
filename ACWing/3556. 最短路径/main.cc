#include <iostream>
#include <cstring>
using namespace std;

const int N = 60, INF = 0x3f3f3f3f;
int n, m, k;
int g[N][N], dist[N];
bool vis[N];

int dijkstra() {
  memset(dist, 0x3f, sizeof dist);
  memset(vis, 0, sizeof vis);
  dist[1] = 0;
  for (int i = 0; i < n; i++) {
    int t = -1;
    for (int j = 1; j <= n; j++)
      if (!vis[j] && (!~t || dist[t] > dist[j])) t = j;

    if (t == n) return dist[t] == INF ? -1 : dist[t];
    vis[t] = true;
    for (int j = 1; j <= n; j++)
      if (!vis[j] && ~g[t][j] && dist[j] > dist[t] + g[t][j])
        dist[j] = dist[t] + g[t][j];
  }

  return -1;
}

int main() {
  int T;
  cin >> T;
  while (T--) {
    memset(g, -1, sizeof g);
    scanf("%d%d%d", &n, &m, &k);
    vector<pair<int, int>> es;
    for (int i = 1; i <= m; i++) {
      int a, b, c;
      scanf("%d%d%d", &a, &b, &c);
      g[a][b] = g[b][a] = c;
      es.push_back({a, b});
    }
    printf("%d\n", dijkstra());
    while (k--) {
      int c;
      scanf("%d", &c);
      int x = es[c - 1].first, y = es[c - 1].second;
      g[x][y] = g[y][x] = -1;
    }
    printf("%d\n", dijkstra());
  }
}