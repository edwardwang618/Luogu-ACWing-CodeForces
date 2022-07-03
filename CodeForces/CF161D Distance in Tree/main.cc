#include <iostream>
#include <cstring>
#include <unordered_map>
using namespace std;

const int N = 5e4 + 10, M = N << 1;
int n, m;
int h[N], e[M], ne[M], idx;
bool vis[N];
int p[N], q[N];

void add(int a, int b) {
  e[idx] = b, ne[idx] = h[a], h[a] = idx++;
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

int get_wc(int u, int from, int tot, int& wc) {
  if (vis[u]) return 0;
  int sz = 1, ms = 0;
  for (int i = h[u]; ~i; i = ne[i]) {
    int v = e[i];
    if (v == from || vis[v]) continue;
    int t = get_wc(v, u, tot, wc);
    sz += t;
    ms = max(ms, t);
  }

  ms = max(ms, tot - sz);
  if (ms <= tot / 2) wc = u;
  return sz;
}

void get_dist(int u, int from, int d, int& qt) {
  if (vis[u]) return;
  q[qt++] = d;
  for (int i = h[u]; ~i; i = ne[i]) {
    int v = e[i];
    if (v != from) get_dist(v, u, d + 1, qt);
  }
}

int calc(int a[], int k) {
  int res = 0;
  unordered_map<int, int> mp;
  for (int i = 0; i < k; i++) {
    res += mp[m - a[i]];
    mp[a[i]]++;
  }
  return res;
}

int dfs(int u) {
  if (vis[u]) return 0;
  get_wc(u, -1, get_sz(u, -1), u);
  vis[u] = true;
  int res = 0, pt = 0;
  for (int i = h[u]; ~i; i = ne[i]) {
    int v = e[i];
    if (vis[v]) continue;
    int qt = 0;
    get_dist(v, u, 1, qt);
    res -= calc(q, qt);
    for (int j = 0; j < qt; j++) {
      if (q[j] == m) res++;
      p[pt++] = q[j];
    }
  }
  res += calc(p, pt);
  for (int i = h[u]; ~i; i = ne[i]) res += dfs(e[i]);
  return res;
}

int main() {
  memset(h, -1, sizeof h);
  scanf("%d%d", &n, &m);
  for (int i = 1; i < n; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    add(a, b), add(b, a);
  }

  printf("%d\n", dfs(1));
}