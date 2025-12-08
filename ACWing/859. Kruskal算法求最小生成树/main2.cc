#include <iostream>
#include <cstring>
#include <queue>

using namespace std;
using PII = pair<int, int>;

const int N = 1e5 + 10, M = 4e5 + 10, INF = 0x3f3f3f3f;
int n, m;
int h[N], e[M], ne[M], w[M], idx;
bool vis[N];
int dist[N];

#define add(a, b, c) \
  e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++

int prim() {
  memset(dist, 0x3f, sizeof dist);
  int res = 0, cnt = 0;
  priority_queue<PII, vector<PII>, greater<>> heap;
  heap.push({0, 1});
  while (heap.size()) {
    auto [dis, u] = heap.top(); heap.pop();
    if (vis[u]) continue;

    vis[u] = true;
    cnt++;
  
    res += dis;

    for (int i = h[u]; ~i; i = ne[i]) {
      int v = e[i], c = w[i];
      if (!vis[v] && dist[v] > c) {
        dist[v] = c;
        heap.push({c, v});
      }
    }
  }

  return cnt == n ? res : INF;
}

int main() {
  scanf("%d%d", &n, &m);
  memset(h, -1, sizeof h);
  while (m--) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    if (a == b) continue;
    add(a, b, c), add(b, a, c);
  }

  int res = prim();
  res == INF ? puts("impossible") : printf("%d\n", res);
}