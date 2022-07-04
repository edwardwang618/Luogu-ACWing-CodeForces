#include <iostream>
#include <cstring>
#include <unordered_set>
using namespace std;

const int N = 1e4 + 10, M = N << 1;
int n, m;
int h[N], e[M], ne[M], w[M], idx;
int sz[N], dist[N], pd;
bool vis[N];
int query[110];
bool res[110];
unordered_set<int> se;

void add(int a, int b, int c) {
  e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}

int get_sz(int u, int from) {
  if (vis[u]) return 0;
  sz[u] = 1;
  for (int i = h[u]; ~i; i = ne[i]) {
    int v = e[i];
    if (v != from) sz[u] += get_sz(v, u);
  }
  return sz[u];
}

bool get_wc(int u, int from, int tot, int &wc) {
  int ms = 0;
  for (int i = h[u]; ~i; i = ne[i]) {
    int v = e[i];
    if (v == from || vis[v]) continue;
    if (get_wc(v, u, tot, wc)) return true;
    ms = max(ms, sz[v]);
  }
  ms = max(ms, tot - sz[u]);
  if (ms <= tot / 2) {
    wc = u;
    return true;
  }
  return false;
}

void get_dist(int u, int from, int d, int &pd) {
  if (vis[u]) return;
  dist[pd++] = d;
  for (int i = h[u]; ~i; i = ne[i]) {
    int v = e[i];
    if (v != from) get_dist(v, u, d + w[i], pd);
  }
}

void dfs(int u) {
  if (vis[u]) return;
  get_wc(u, -1, get_sz(u, -1), u);
  vis[u] = true;
  se.clear();
  for (int i = h[u]; ~i; i = ne[i]) {
    int v = e[i];
    pd = 0;
    get_dist(v, -1, w[i], pd);
    for (int j = 1; j <= m; j++) {
      if (res[j]) continue;
      int k = query[j];
      for (int l = 0; l < pd; l++)
        if (k >= dist[l] && se.count(k - dist[l])) {
          res[j] = true;
          break;
        }
    }
    for (int l = 0; l < pd; l++) se.insert(dist[l]);
  }

  for (int j = 1; j <= m; j++) {
    if (res[j]) continue;
    if (se.count(query[j])) res[j] = true;
  }

  for (int i = h[u]; ~i; i = ne[i]) dfs(e[i]);
}

int main() {
  memset(h, -1, sizeof h);
  scanf("%d%d", &n, &m);
  for (int i = 1; i < n; i++) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    add(a, b, c), add(b, a, c);
  }

  for (int i = 1; i <= m; i++) scanf("%d", &query[i]);
  dfs(1);
  for (int i = 1; i <= m; i++)
    res[i] ? puts("AYE") : puts("NAY");
}