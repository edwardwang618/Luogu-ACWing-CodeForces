#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 4e4 + 10, M = N << 1;
int n, m;
int h[N], e[M], ne[M], w[M], idx;
bool vis[N];
int p[N], q[N];

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

int get_wc(int u, int from, int tot, int &wc) {
  if (vis[u]) return 0;
  int sz = 1, ms = 0;
  for (int i = h[u]; ~i; i = ne[i]) {
    int v = e[i];
    if (v == from || vis[v]) continue;
    int t = get_wc(v, u, tot, wc);
    ms = max(ms, t);
    sz += t;
  }

  ms = max(ms, tot - sz);
  if (ms <= tot / 2) wc = u;
  return sz;
}

void get_dist(int u, int from, int d, int &qt) {
  if (vis[u]) return;
  q[qt++] = d;
  for (int i = h[u]; ~i; i = ne[i]) {
    int v = e[i];
    if (v != from) get_dist(v, u, d + w[i], qt);
  }
}

int calc(int a[], int k) {
  sort(a, a + k);
  int res = 0;
  for (int i = 0, j = k - 1; i < j; i++) {
    while (i < j && a[i] + a[j] > m) j--;
    res += j - i;
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
    get_dist(v, u, w[i], qt);
    res -= calc(q, qt);
    for (int j = 0; j < qt; j++) {
      if (q[j] <= m) res++;
      p[pt++] = q[j];
    }
  }
  res += calc(p, pt);
  for (int i = h[u]; ~i; i = ne[i]) res += dfs(e[i]);
  return res;
}

int main() {
  memset(h, -1, sizeof h);
  scanf("%d", &n);
  for (int i = 1; i <= n - 1; i++) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    add(a, b, c), add(b, a, c);
  }

  scanf("%d", &m);
  printf("%d\n", dfs(1));
}