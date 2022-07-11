#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 15e4 + 10, M = N << 1;
int n, m, A;
int h[N], e[M], ne[M], w[M], idx;
int age[N];
bool vis[N];
struct Father {
  int u, num;
  long dist;
};
vector<Father> f[N];
struct Son {
  int age;
  long dist;
  bool operator<(const Son &t) const {
    return age < t.age;
  }
};
vector<Son> son[N][3];

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
    if (v != from) {
      int t = get_wc(v, u, tot, wc);
      ms = max(ms, t);
      sz += t;
    }
  }

  ms = max(ms, tot - sz);
  if (ms <= tot / 2) wc = u;
  return sz;
}

void get_dist(int u, int from, long dist, int wc, int k, vector<Son> &p) {
  if (vis[u]) return;
  f[u].push_back({wc, k, dist});
  p.push_back({age[u], dist});
  for (int i = h[u]; ~i; i = ne[i]) {
    int v = e[i];
    if (v != from) get_dist(v, u, dist + w[i], wc, k, p);
  }
}

void dfs(int u) {
  if (vis[u]) return;
  get_wc(u, -1, get_sz(u, -1), u);
  vis[u] = true;

  for (int i = h[u], k = 0; ~i; i = ne[i]) {
    int v = e[i];
    if (vis[v]) continue;
    auto &p = son[u][k];
    p.push_back({-1, 0}), p.push_back({A + 1, 0});
    get_dist(v, -1, w[i], u, k++, p);
    sort(p.begin(), p.end());
    for (int i = 1; i < p.size(); i++)
      p[i].dist += p[i - 1].dist;
  }

  for (int i = h[u]; ~i; i = ne[i]) dfs(e[i]);
}

long query(int u, int l, int r) {
  long res = 0;
  for (auto &t : f[u]) {
    int g = age[t.u];
    if (l <= g && g <= r) res += t.dist;
    for (int i = 0; i < 3; i++) {
      if (i == t.num) continue;
      auto &p = son[t.u][i];
      if (p.empty()) continue;
      int a = lower_bound(p.begin(), p.end(), Son({l, -1})) - p.begin();
      int b = lower_bound(p.begin(), p.end(), Son({r + 1, -1})) - p.begin();
      res += t.dist * (b - a) + p[b - 1].dist - p[a - 1].dist;
    }
  }

  for (int i = 0; i < 3; i++) {
    auto &p = son[u][i];
    if (p.empty()) continue;
    int a = lower_bound(p.begin(), p.end(), Son({l, -1})) - p.begin();
    int b = lower_bound(p.begin(), p.end(), Son({r + 1, -1})) - p.begin();
    res += p[b - 1].dist - p[a - 1].dist;
  }

  return res;
}

int main() {
  memset(h, -1, sizeof h);
  scanf("%d%d%d", &n, &m, &A);
  for (int i = 1; i <= n; i++) scanf("%d", &age[i]);
  for (int i = 1; i < n; i++) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    add(a, b, c), add(b, a, c);
  }
  dfs(1);

  long res = 0;
  while (m--) {
    int u, a, b;
    scanf("%d%d%d", &u, &a, &b);
    int l = (a + res) % A, r = (b + res) % A;
    if (l > r) swap(l, r);
    res = query(u, l, r);
    printf("%ld\n", res);
  }
}