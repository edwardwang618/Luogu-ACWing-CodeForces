#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

using PI = pair<pair<int, int>, int>;

const int N = 510, M = 610;
int n, m, st, ed;
int h[N], e[M << 1], ne[M << 1], c[M << 1], d[M << 1], idx;
bool vis[N];
int dist_glob[N], cost_glob[N];
int pre[N];

#define add(a, b, cost, dist) \
  e[idx] = b, ne[idx] = h[a], c[idx] = cost, d[idx] = dist, h[a] = idx++

pair<int, int> dijkstra() {
  memset(dist_glob, 0x3f, sizeof dist_glob);
  memset(cost_glob, 0x3f, sizeof cost_glob);
  priority_queue<PI, vector<PI>, greater<>> heap;
  heap.push({{0, 0}, ed});
  while (heap.size()) {
    auto t = heap.top();
    heap.pop();
#define x first
#define y second
    int dist = t.x.x, cost = t.x.y, u = t.y;
    if (u == st) return {dist, cost};
    if (vis[u]) continue;
    vis[u] = true;
    dist_glob[u] = dist;
    cost_glob[u] = cost;
    for (int i = h[u]; ~i; i = ne[i]) {
      int v = e[i], cost_v = c[i], dist_v = d[i];
      if (!vis[v] &&
          (dist_glob[v] > dist + dist_v ||
           dist_glob[v] == dist + dist_v && cost_glob[v] > cost + cost_v)) {
        dist_glob[v] = dist + dist_v;
        cost_glob[v] = cost + cost_v;
        pre[v] = u;
        heap.push({{dist_glob[v], cost + cost_v}, v});
      }
    }
  }
  return {-1, -1};
}

int main() {
  memset(h, -1, sizeof h);
  scanf("%d%d%d%d", &n, &m, &st, &ed);
  for (int i = 1; i <= m; i++) {
    int a, b, cost, dist;
    scanf("%d%d%d%d", &a, &b, &cost, &dist);
    add(a, b, dist, cost), add(b, a, dist, cost);
  }

  auto [a, b] = dijkstra();
  int x = st;
  while (x != ed) {
    printf("%d ", x);
    x = pre[x];
  }
  printf("%d %d %d\n", ed, dist_glob[st], cost_glob[st]);
}