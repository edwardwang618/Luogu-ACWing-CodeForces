#include <iostream>
#include <cstring>
using namespace std;

const int N = 2010, M = 1e5 + 10;
int n, m, x, y;
double g[N][N], dist[N];
bool vis[N];

double dijkstra() {
  dist[x] = 1.0;
  for (int i = 0; i < n; i++) {
    int t = -1;
    for (int j = 1; j <= n; j++)
      if (!vis[j] && (t == -1 || dist[j] > dist[t])) t = j;

    if (t == y) return dist[y];
    vis[t] = true;
    for (int j = 1; j <= n; j++) {
      if (!vis[j]) dist[j] = max(dist[j], dist[t] * g[t][j]);
    }
  }

  return -1;
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    g[a][b] = g[b][a] = max(g[a][b], (100.0 - c) / 100.0);
  }

  scanf("%d%d", &x, &y);
  printf("%.8lf\n", 100.0 / dijkstra());
}