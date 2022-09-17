#include <iostream>
#include <cstring>
#include <queue>
#define x first
#define y second
using namespace std;
using PLII = pair<long, pair<int, int>>;

const int N = 55, M = 2010;
int n, m, K;
int h[N], e[M], ne[M], w[M], idx;
long dist[N][N];
bool vis[N][N];

void add(int a, int b, int c) {
  e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}

long dijkstra() {
  memset(dist, 0x3f, sizeof dist);
  memset(vis, 0, sizeof vis);
  dist[1][K] = 0;
  priority_queue<PLII, vector<PLII>, greater<PLII>> heap;
  heap.push({0, {1, K}});
  while (heap.size()) {
    auto t = heap.top(); heap.pop();
    int u = t.y.x, k = t.y.y;
    if (u == n) return t.x;
    if (vis[u][k]) continue;
    vis[u][k] = true;
    for (int i = h[u]; ~i; i = ne[i]) {
      int v = e[i];
      if (!vis[v][k] && dist[v][k] > dist[u][k] + w[i]) {
        dist[v][k] = dist[u][k] + w[i];
        heap.push({dist[v][k], {v, k}});
      }
      if (k && !vis[v][k - 1] && dist[v][k - 1] > dist[u][k] + w[i] / 2) {
        dist[v][k - 1] = dist[u][k] + w[i] / 2;
        heap.push({dist[v][k - 1], {v, k - 1}});
      }
    }
  }

  return -1;
}

int main() {
  memset(h, -1, sizeof h);
  scanf("%d%d%d", &n, &m, &K);
  for (int i = 1; i <= m; i++) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    add(a, b, c), add(b, a, c);
  }

  printf("%ld\n", dijkstra());
}