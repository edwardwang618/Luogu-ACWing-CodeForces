#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

using PII = pair<int, int>;

const int N = 1.5e5 + 10, INF = 0x3f3f3f3f;
int n, m;
int h[N], e[N], ne[N], w[N], idx;
int dist[N];

#define add(a, b, c) e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++

int dijkstra() {
  memset(dist, 0x3f, sizeof dist);
  dist[1] = 0;
  priority_queue<PII, vector<PII>, greater<>> heap;
  heap.emplace(0, 1);
  while (heap.size()) {
    auto [dis, u] = heap.top(); heap.pop();
    if (dis > dist[u]) continue;
    if (u == n) return dis;
    
    for (int i = h[u]; ~i; i = ne[i]) {
      int v = e[i], c = w[i];
      if (dist[v] > dis + c) {
        dist[v] = dis + c;
        heap.emplace(dist[v], v);
      }
    }
  }

  return -1;
}

int main() {
  scanf("%d%d", &n, &m);
  memset(h, -1, sizeof h);
  while (m--) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    if (a == b) continue;
    add(a, b, c);
  }

  printf("%d\n", dijkstra());
}