#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

const int N = 110;
int n;
int g[N][N];
int dist[N];
bool vis[N];

int prim() {
  memset(dist, 0x3f, sizeof dist);
  int res = 0;
  for (int i = 1; i <= n; i++) {
    int t = -1;
    for (int j = 1; j <= n; j++)
      if (!vis[j] && (!~t || dist[t] > dist[j])) t = j;

    if (i > 1) res += dist[t];
    vis[t] = true;
    for (int j = 1; j <= n; j++)
      if (!vis[j]) dist[j] = min(dist[j], g[t][j]);
  }

  return res;
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) scanf("%d", &g[i][j]);

  printf("%d\n", prim());
}