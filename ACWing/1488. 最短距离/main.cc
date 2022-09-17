#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
using PII = pair<int, int>;

const int N = 1e5 + 10, M = 3e5 + 10;
int n, m, K, Q;
int h[N], e[M], ne[M], w[M], idx;
int dist[N];
bool vis[N];

void add(int a, int b, int c) {
  e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}

int dijkstra(int x) {
  memset(dist, 0x3f, sizeof dist);
  memset(vis, 0, sizeof vis);
  priority_queue<PII, vector<PII>, greater<PII>> heap;
  heap.push({0, x});
  dist[x] = 0;
  while (heap.size()) {
    auto t = heap.top(); heap.pop();
    int d = t.first, u = t.second;
    if (vis[u]) continue;
    vis[u] = true;

    for (int i = h[u]; ~i; i = ne[i]) {
      int v = e[i];
      if (!vis[v] && dist[v] > dist[u] + w[i]) {
        dist[v] = dist[u] + w[i];
        heap.push({dist[v], v});
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

  scanf("%d", &K);
  while (K--) {
    int x;
    scanf("%d", &x);
    add(0, x, 0);
  }
  dijkstra(0);

  scanf("%d", &Q);
  while (Q--) {
    int x;
    scanf("%d", &x);
    printf("%d\n", dist[x]);
  }
}