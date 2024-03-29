#include <iostream>
#include <cstring>
using namespace std;

const int N = 510, INF = 0x3f3f3f3f;
int n, m;
int g[N][N], dist[N];
bool st[N];

int dijkstra() {
  memset(dist, 0x3f, sizeof dist);
  dist[1] = 0;

  for (int i = 0; i < n; i++) {
    int t = -1;
    for (int j = 1; j <= n; j++)
      if (!st[j] && (t == -1 || dist[t] > dist[j])) t = j;

    if (t == n) break;

    st[t] = true;
    for (int j = 1; j <= n; j++)
      if (!st[j]) dist[j] = min(dist[j], dist[t] + g[t][j]);
  }

  return dist[n] == INF ? -1 : dist[n];
}

int main() {
  cin >> n >> m;

  memset(g, 0x3f, sizeof g);

  while (m--) {
    int a, b, c;
    cin >> a >> b >> c;
    if (a == b) g[a][b] = 0;
    else g[a][b] = min(g[a][b], c);
  }

  cout << dijkstra() << endl;
}