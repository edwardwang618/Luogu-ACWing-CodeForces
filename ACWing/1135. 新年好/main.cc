#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, int> PII;

const int N = 50010, M = 200010, INF = 0x3f3f3f3f;
int n, m;
int src[6];
int h[N], e[M], ne[M], w[M], idx;
int dist[6][N];
bool vis[N];
int res = INF;

void add(int a, int b, int c) {
  e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void dijkstra(int start, int dis[]) {
  memset(vis, 0, sizeof vis);
  priority_queue<PII, vector<PII>, greater<PII>> heap;
  heap.push({0, start});
  dis[start] = 0;

  while (heap.size()) {
    auto [d, v] = heap.top();
    heap.pop();

    if (vis[v])
      continue;
    vis[v] = true;
    for (int i = h[v]; ~i; i = ne[i]) {
      int j = e[i];
      if (!vis[j] && dis[j] > d + w[i]) {
        dis[j] = d + w[i];
        heap.push({dis[j], j});
      }
    }
  }
}

void dfs(int u, int start, int distance) {
  if (u == 6) {
    res = min(res, distance);
    return;
  }

  for (int i = 1; i <= 5; i++)
    if (!vis[i]) {
      int next = src[i];
      vis[i] = true;
      dfs(u + 1, i, distance + dist[start][next]);
      vis[i] = false;
    }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m;
  src[0] = 1;
  for (int i = 1; i <= 5; i++)
    cin >> src[i];

  memset(h, -1, sizeof h);
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    add(a, b, c), add(b, a, c);
  }

  memset(dist, 0x3f, sizeof dist);
  for (int i = 0; i < 6; i++)
    dijkstra(src[i], dist[i]);

  memset(vis, 0, sizeof vis);
  dfs(1, 0, 0);
  printf("%d\n", res);
}