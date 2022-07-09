#include <iostream>
#include <cstring>
#include <map>
using namespace std;
using PII = pair<int, int>;

const int N = 2e5 + 10, M = N << 1;
int n, m;
int h[N], e[M], ne[M], w[M], idx;
int sz[N];
bool vis[N];
map<int, int> mp;
PII p[N];
int res;

void add(int a, int b, int c) {
  e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}

int get_sz(int u, int from) {
  if (vis[u]) return 0;
  int sz = 1;
  for (int i = h[u]; ~i; i = ne[i]) {
    int v = e[i];
    if (v != from) sz += get_sz(v, u);
  }

  return sz;
}

bool get_wc(int u, int from, int tot, int& wc) {
  if (vis[u]) return false;
  int ms = 0;
  sz[u] = 1;
  for (int i = h[u]; ~i; i = ne[i]) {
    int v = e[i];
    if (v != from && !vis[v]) {
      if (get_wc(v, u, tot, wc)) return true;
      ms = max(ms, sz[v]);
      sz[u] += sz[v];
    }
  }
  ms = max(ms, tot - sz[u]);
  if (ms <= tot / 2) {
    wc = u;
    return true;
  }
  return false;
}

void get_dist(int u, int from, int dist, int cnt, int& pd) {
  if (vis[u] || dist > m || cnt >= res) return;
  p[pd++] = {dist, cnt};
  for (int i = h[u]; ~i; i = ne[i]) {
    int v = e[i];
    if (v != from) get_dist(v, u, dist + w[i], cnt + 1, pd);
  }
}

void dfs(int u) {
  if (vis[u]) return;
  get_wc(u, -1, get_sz(u, -1), u);
  vis[u] = true;
  mp.clear();
  for (int i = h[u]; ~i; i = ne[i]) {
    int v = e[i];
    int pd = 0;
    get_dist(v, u, w[i], 1, pd);
    for (int i = 0; i < pd; i++) {
      int dist = p[i].first, cnt = p[i].second;
      if (mp.count(m - dist)) res = min(res, cnt + mp[m - dist]);
      if (dist == m) res = min(res, cnt);
    }
    for (int i = 0; i < pd; i++) {
      int dist = p[i].first, cnt = p[i].second;
      if (!mp.count(dist)) mp[dist] = cnt;
      else mp[dist] = min(mp[dist], cnt);
    }
  }

  for (int i = h[u]; ~i; i = ne[i]) dfs(e[i]);
}

int main() {
  memset(h, -1, sizeof h);
  res = N;
  scanf("%d%d", &n, &m);
  for (int i = 1; i < n; i++) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    add(a, b, c), add(b, a, c);
  }
  
  dfs(0);
  res < N ? printf("%d\n", res) : puts("-1");
}