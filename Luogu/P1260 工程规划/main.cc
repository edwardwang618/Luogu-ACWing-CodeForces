#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int N = 1010, M = 5010;
int n, m;
int h[N], e[M], ne[M], w[M], idx;
int dist[N], cnt[N];
bool vis[N];

void add(int a, int b, int c) {
  e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}

bool spfa() {
  queue<int> q;
  for (int i = 1; i <= n; i++) {
    q.push(i);
    vis[i] = true;
  }

  while (q.size()) {
    int t = q.front(); q.pop();
    vis[t] = false;
    for (int i = h[t]; ~i; i = ne[i]) {
      int v = e[i];
      if (dist[v] > dist[t] + w[i]) {
        dist[v] = dist[t] + w[i];
        cnt[v] = cnt[t] + 1;
        if (cnt[v] > n - 1) return false;
        if (!vis[v]) {
          q.push(v);
          vis[v] = false;
        }
      }
    }
  }

  return true;
}

int main() {
  memset(h, -1, sizeof h);
  scanf("%d%d", &n, &m);

  while (m--) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    add(b, a, c);
  }

  if (!spfa()) puts("NO SOLUTION");
  else {
    int mi = 0x3f3f3f3f;
    for (int i = 1; i <= n; i++) mi = min(mi, dist[i]);
    for (int i = 1; i <= n; i++) printf("%d\n", dist[i] - mi);
  }
}