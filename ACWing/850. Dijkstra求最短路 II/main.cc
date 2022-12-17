#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
using PII = pair<int, int>;

const int N = 150010, INF = 0x3f3f3f3f;
int n, m;
int h[N], e[N], w[N], ne[N], idx;
int dist[N];
bool vis[N];

void add(int a, int b, int c) {
  e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

int dijkstra() {
  memset(dist, 0x3f, sizeof dist);
  dist[1] = 0;

  priority_queue<PII, vector<PII>, greater<PII> > heap;
  heap.push({0, 1});

  while (heap.size()) {
    auto [dis, v] = heap.top(); heap.pop();
    if (vis[v]) continue;
    if (v == n) break;

    vis[v] = true;
    for (int i = h[v]; ~i; i = ne[i]) {
      int j = e[i];
      if (!vis[j] && dist[j] > dis + w[i]) {
        dist[j] = dis + w[i];
        heap.push({dist[j], j});
      }
    }
  }

  return dist[n] == INF ? -1 : dist[n];
}

int main() {
  memset(h, -1, sizeof h);
  cin >> n >> m;

  while (m--) {
    int a, b, c;
    cin >> a >> b >> c;
    add(a, b, c);
  }

  cout << dijkstra() << endl;
}