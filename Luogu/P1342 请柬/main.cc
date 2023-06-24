#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

using ll = long long;
using PLI = pair<ll, int>;

const int N = 1e6 + 10;
int n, m;
int h[2][N], e[2][N], ne[2][N], w[2][N], idx[2];
bool vis[N];
ll dist[N];
priority_queue<PLI, vector<PLI>, greater<>> heap;

#define add(a, b, c, i)                                        \
  e[i][idx[i]] = b, ne[i][idx[i]] = h[i][a], w[i][idx[i]] = c, \
  h[i][a] = idx[i]++

ll dijkstra(int i) {
  memset(dist, 0x3f, sizeof dist);
  memset(vis, 0, sizeof vis);
  heap.push({0, 1});
  while (heap.size()) {
    auto t = heap.top(); heap.pop();
    ll d = t.first;
    int u = t.second;
    if (vis[u]) continue;
    vis[u] = true;
    dist[u] = d;
    for (int j = h[i][u]; ~j; j = ne[i][j]) {
      int v = e[i][j];
      if (!vis[v] && dist[v] > d + w[i][j]) {
        dist[v] = d + w[i][j];
        heap.push({dist[v], v});
      }
    }
  }

  ll res = 0;
  for (int i = 1; i <= n; i++) res += dist[i];
  return res;
}

int main() {
  scanf("%d%d", &n, &m);
  memset(h, -1, sizeof h);
  while (m--) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    add(a, b, c, 0), add(b, a, c, 1);
  }

  printf("%lld\n", dijkstra(0) + dijkstra(1));
}