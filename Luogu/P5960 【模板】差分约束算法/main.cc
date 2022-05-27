#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int N = 5010, M = N;
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
        if (cnt[v] > n - 1) {
          return false;
        }

        if (!vis[v]) {
          q.push(v);
          vis[v] = true;
        }
      }
    }
  }

  return true;
}

int main() {
  memset(h, -1, sizeof h);

  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    add(b, a, c);
  }

  bool found = spfa();
  if (!found) puts("NO");
  else for (int i = 1; i <= n; i++) printf("%d ", dist[i]);
}