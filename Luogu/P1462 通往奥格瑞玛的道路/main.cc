#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
using PLI = pair<long, int>;

const int N = 10010, M = 100010;
int n, m, b, fee[N];
int h[N], e[M], ne[M], w[M], idx;
long dist[N];
bool vis[N];

#define add(a, b, c) \
e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++

int dijkstra(int maxf) {
  memset(dist, 0x3f, sizeof dist);
  memset(vis, 0, sizeof vis);
  dist[1] = 0;
  priority_queue<PLI, vector<PLI>, greater<PLI>> heap;
  heap.push({0, 1});
  while (heap.size()) {
    auto t = heap.top(); heap.pop();
    int u = t.second;
    if (vis[u]) continue;
    if (u == n) break;
    vis[u] = true;
    for (int i = h[u]; ~i; i = ne[i]) {
      int v = e[i];
      if (fee[v] > maxf) continue;
      if (dist[u] + w[i] < dist[v]) {
        dist[v] = dist[u] + w[i];
        heap.push({dist[v], v});
      }
    }
  }

  return dist[n];
}

int main() {
  memset(h, -1, sizeof h);
  scanf("%d%d%d", &n, &m, &b);
  int l = 0, r = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &fee[i]);
    r = max(r, fee[i]);
  }
  l = max(fee[1], fee[n]);
  for (int i = 1; i <= m; i++) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    add(a, b, c), add(b, a, c);
  }

  while (l < r) {
    int mid = l + (r - l >> 1);
    if (dijkstra(mid) <= b) r = mid;
    else l = mid + 1;
  }

  if (dijkstra(l) > b) puts("AFK");
  else printf("%d\n", l);
}