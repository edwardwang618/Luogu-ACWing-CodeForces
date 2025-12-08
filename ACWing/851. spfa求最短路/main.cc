#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int N = 1e5 + 10, INF = 0x3f3f3f3f;
int n, m;
int h[N], e[N], ne[N], w[N], idx;
queue<int> q;
int dist[N];
bool vis[N];

void add(int a, int b, int c) {
  e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}

int spfa() {
  memset(dist, 0x3f, sizeof dist);
  dist[1] = 0;
  q.push(1);
  vis[1] = true;
  while (q.size()) {
    int u = q.front(); q.pop();
    vis[u] = false;
    for (int i = h[u]; ~i; i = ne[i]) {
      int v = e[i];
      if (dist[v] > dist[u] + w[i]) {
        dist[v] = dist[u] + w[i];
        if (!vis[v]) {
          q.push(v);
          vis[v] = true;
        }
      }
    }
  }
  
  return dist[n];
}

int main() {
  scanf("%d%d", &n, &m);
  memset(h, -1, sizeof h);
  for (int i = 1; i <= m; i++) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    add(a, b, c);
  }
  
  int res = spfa();
  res == INF ? puts("impossible") : printf("%d\n", res);
}