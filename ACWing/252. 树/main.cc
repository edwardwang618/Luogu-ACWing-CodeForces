#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1e4 + 10, M = N << 1;
int n, m;
int h[N], e[M], w[M], ne[M], idx;
bool vis[N];
int p[N], q[N];

void add(int a, int b, int c) {
  e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}

int get_sz(int u, int from) {
  if (vis[u]) return 0;
  int res = 1;
  for (int i = h[u]; ~i; i = ne[i]) {
    int v = e[i];
    if (v != from) res += get_sz(v, u);
  }
  return res;
}

int get_wc(int u, int from, int tot, int& wc) {
  int sum = 1, ms = 0;
  for (int i = h[u]; ~i; i = ne[i]) {
    int v = e[i];
    if (v == from || vis[v]) continue;
    int t = get_wc(v, u, tot, wc);
    ms = max(ms, t);
    sum += t;
  }
  ms = max(ms, tot - sum);
  if (ms <= tot / 2) wc = u;
  return sum;
}

void get_dist(int u, int from, int dist, int& qt) {
  if (vis[u]) return;
  q[qt++] = dist;
  for (int i = h[u]; ~i; i = ne[i]) {
    int v = e[i];
    if (v != from) get_dist(v, u, dist + w[i], qt);
  }
}

int calc(int a[], int k) {
  sort(a, a + k);
  int res = 0;
  for (int i = 0, j = k - 1; i < j;)
    if (a[i] + a[j] <= m) res += j - i, i++;
    else j--;

  return res;
}

int dfs(int u) {
  if (vis[u]) return 0;
  int res = 0;
  get_wc(u, -1, get_sz(u, -1), u);
  vis[u] = true;

  int pt = 0;
  for (int i = h[u]; ~i; i = ne[i]) {
    int v = e[i], qt = 0;
    get_dist(v, -1, w[i], qt);
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
  while (scanf("%d%d", &n, &m), n || m) {
    memset(h, -1, sizeof h);
    memset(vis, 0, sizeof vis);
    idx = 0;
    for (int i = 1; i <= n - 1; i++) {
      int a, b, c;
      scanf("%d%d%d", &a, &b, &c);
      add(a, b, c), add(b, a, c);
    }

    printf("%d\n", dfs(0));
  }
}