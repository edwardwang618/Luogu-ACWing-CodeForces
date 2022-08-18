#include <iostream>
#include <cstring>
using namespace std;

const int N = 510, M = 10010;
int n, m, k;
struct Edge {
  int u, v, w;
} e[M];
int dist[2][N];

int bellman_ford() {
  memset(dist, 0x3f, sizeof dist);
  dist[0][1] = dist[1][1] = 0;
    
  for (int i = 1; i <= k; i++)
    for (int j = 1; j <= m; j++) {
      int u = e[j].u, v = e[j].v, w = e[j].w;
      dist[i & 1][v] = min(dist[i & 1][v], dist[i - 1 & 1][u] + w);
    }
  
  if (dist[k & 1][n] > 0x3f3f3f3f / 2) return 0x3f3f3f3f;
  else return dist[k & 1][n];
}

int main() {
  scanf("%d%d%d", &n, &m, &k);
  
  for (int i = 1; i <= m; i++) {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    e[i] = {u, v, w};
  }
  
  int res = bellman_ford();
  
  if (res == 0x3f3f3f3f) puts("impossible");
  else printf("%d\n", res);
  
  return 0;
}