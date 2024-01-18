#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

const int N = 1e4 + 10, M = 2e5 + 10;
int n, m;
int st, en;
int h1[N], e1[M], ne1[M], idx1;
int h2[N], e2[M], ne2[M], idx2;
bool vis[N], cannot_use[N];

#define add(a, b)                                                \
  e1[idx1] = b, ne1[idx1] = h1[a], h1[a] = idx1++, e2[idx2] = a, \
  ne2[idx2] = h2[b], h2[b] = idx2++

void dfs(int u) {
  vis[u] = true;
  for (int i = h2[u]; ~i; i = ne2[i])
    if (!vis[e2[i]]) dfs(e2[i]);
}

int bfs() {
  if (cannot_use[st]) return -1;
  memset(vis, 0, sizeof vis);
  queue<int> q;
  q.push(st);
  vis[st] = true;
  int res = 0;
  while (q.size()) {
    res++;
    for (int i = q.size(); i; i--) {
      auto t = q.front();
      q.pop();
      for (int j = h1[t]; ~j; j = ne1[j]) {
        int ne = e1[j];
        if (vis[ne] || cannot_use[ne]) continue;
        if (ne == en) return res;
        vis[ne] = true;
        q.push(ne);
      }
    }
  }
  return -1;
}

int main() {
  memset(h1, -1, sizeof h1);
  memset(h2, -1, sizeof h2);
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    add(a, b);
  }
  scanf("%d%d", &st, &en);
  dfs(en);
  for (int i = 1; i <= n; i++)
    for (int j = h1[i]; ~j; j = ne1[j]) {
      int v = e1[j];
      if (!vis[v]) {
        cannot_use[i] = true;
        break;
      }
    }
  printf("%d\n", bfs());
}