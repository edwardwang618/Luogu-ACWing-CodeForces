#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1e4 + 10, M = N << 1;
int n, m;
int h[N], e[M], w[M], ne[M], idx;
int sz[N];
bool vis[N];
int p[N];

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

int get_dist(int u, int from, int dist, int &pt) {
  if (vis[u]) return 0;
  int cnt = 1;
  p[pt++] = dist;
  for (int i = h[u]; ~i; i = ne[i]) {
    int v = e[i];
    if (v != from) cnt += get_dist(v, u, dist + w[i], pt);
  }

  return cnt;
}

int calc(int l, int r) {
  sort(p + l, p + r + 1);
  int res = 0;
  for (int i = l, j = r; i < j;)
    if (p[i] + p[j] <= m) res += j - i, i++;
    else j--;

  return res;
}

int dfs(int u) {
  if (vis[u]) return 0;
  get_wc(u, -1, get_sz(u, -1), u);
  vis[u] = true;

  int res = 0, pt = 0;
  for (int i = h[u]; ~i; i = ne[i]) {
    int v = e[i];
    int cnt = get_dist(v, -1, w[i], pt);
    if (!cnt) continue;
    res -= calc(pt - cnt, pt - 1);
    int l = pt - cnt, r = pt - 1;
    while (l < r) {
      int mid = l + (r - l + 1 >> 1);
      if (p[mid] <= m) l = mid;
      else r = mid - 1;
    }

    if (p[l] <= m) res += l - (pt - cnt) + 1;
  }
  res += calc(0, pt - 1);
  
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
      a++, b++;
      add(a, b, c), add(b, a, c);
    }

    printf("%d\n", dfs(1));
  }
}