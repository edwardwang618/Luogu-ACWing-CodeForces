#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
using PII = pair<int, int>;

const int N = 110, M = 2e4 + 10;
int n, m;
int h[N], e[M], ne[M], w[M], idx;
int dist[N];
bool vis[N];
int path[N];
#define add(a, b, c) e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++

int dijkstra(bool flag) {
  memset(dist, 0x3f, sizeof dist);
  memset(vis, 0, sizeof vis);
  priority_queue<PII, vector<PII>, greater<>> heap;
  heap.push({0, 1});
  dist[1] = 0;
  while (heap.size()) {
    auto t = heap.top(); heap.pop();
    int u = t.second;
    if (vis[u]) continue;
    if (u == n) return dist[n];
    vis[u] = true;
    for (int i = h[u]; ~i; i = ne[i]) {
      int v = e[i];
      if (dist[v] > dist[u] + w[i]) {
        dist[v] = dist[u] + w[i];
        heap.push({dist[v], v});
        if (flag) path[v] = i;
      }
    }
  }

  return -1;
}

int main() {
  memset(h, -1, sizeof h);
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    add(a, b, c), add(b, a, c);
  }

  int x = dijkstra(true), y = x;
  for (int i = 2; i <= n; i++) {
    w[path[i]] *= 2;
    y = max(y, dijkstra(false));
    w[path[i]] /= 2;
  }

  printf("%d\n", y - x);
}