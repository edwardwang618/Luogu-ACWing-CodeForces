#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
using PLI = pair<long, int>;

const int N = 1e5 + 10, M = 2e5 + 10;
int n, m;
int h[N], e[M], ne[M], w[M], idx;
long dist[N];
int pre[N];
bool vis[N];
int res[N];

void add(int a, int b, int c) {
  e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}

void dijkstra() {
  memset(dist, 0x3f, sizeof dist);
  dist[1] = 0;
  priority_queue<PLI, vector<PLI>, greater<>> heap;
  heap.push({0, 1});
  pre[1] = 1;
  while (heap.size()) {
    auto t = heap.top(); heap.pop();
    int v = t.second;
    if (vis[v]) continue;
    if (v == n) break;
    vis[v] = true;
    for (int i = h[v]; ~i; i = ne[i]) {
      int j = e[i];
      if (dist[j] > dist[v] + w[i]) {
        dist[j] = dist[v] + w[i];
        pre[j] = v;
        heap.push({dist[j], j});
      }
    }
  }
}

int main() {
  memset(h, -1, sizeof h);
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    add(a, b, c), add(b, a, c);
  }

  dijkstra();
  if (dist[n] == 0x3f3f3f3f3f3f3f3f) puts("-1");
  else {
    int cnt = 0;
    while(n != 1) {
      res[cnt++] = n;
      n = pre[n];
    }
    res[cnt++] = 1;
    for (int i = cnt - 1; i >= 0; i--) printf("%d ", res[i]);
  }
}