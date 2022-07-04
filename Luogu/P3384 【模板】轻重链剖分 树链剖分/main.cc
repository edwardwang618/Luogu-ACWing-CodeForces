#include <iostream>
#include <cstring>
using namespace std;

const int N = 1e5 + 10, M = N * 2;
int n, m, rt, P;
int h[N], e[M], ne[M], idx;
long w[N], nw[N];
int id[N], cnt;
int dep[N], sz[N], top[N], fa[N], son[N];
struct Tree {
  int l, r;
  long sum, add;
} tr[N << 2];

void add(int a, int b) {
  e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void dfs1(int u, int from, int depth) {
  dep[u] = depth, fa[u] = from, sz[u] = 1;
  for (int i = h[u]; ~i; i = ne[i]) {
    int v = e[i];
    if (v == from) continue;
    dfs1(v, u, depth + 1);
    sz[u] += sz[v];
    if (sz[son[u]] < sz[v]) son[u] = v;
  }
}

void dfs2(int u, int t) {
  id[u] = ++cnt, nw[cnt] = w[u], top[u] = t;
  if (!son[u]) return;
  dfs2(son[u], t);
  for (int i = h[u]; ~i; i = ne[i]) {
    int v = e[i];
    if (v == fa[u] || v == son[u]) continue;
    dfs2(v, v);
  }
}

void pushup(int u) {
  tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
}

void pushdown(int u) {
  auto &root = tr[u], &l = tr[u << 1], &r = tr[u << 1 | 1];
  if (root.add) {
    l.sum = (l.sum + root.add * (l.r - l.l + 1)) % P;
    l.add = (l.add + root.add) % P;
    r.sum = (r.sum + root.add * (r.r - r.l + 1)) % P;
    r.add = (r.add + root.add) % P;
    root.add = 0;
  }
}

void build(int u, int l, int r) {
  tr[u] = {l, r, nw[l], 0};
  if (l == r) return;
  int mid = l + r >> 1;
  build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
  pushup(u);
}

void update(int u, int l, int r, long k) {
  if (l <= tr[u].l && tr[u].r <= r) {
    tr[u].add = (tr[u].add + k) % P;
    tr[u].sum = (tr[u].sum + k * (tr[u].r - tr[u].l + 1)) % P;
    return;
  }

  pushdown(u);
  int mid = tr[u].l + tr[u].r >> 1;
  if (l <= mid) update(u << 1, l, r, k);
  if (r > mid) update(u << 1 | 1, l, r, k);
  pushup(u);
}

long query(int u, int l, int r) {
  if (l <= tr[u].l && tr[u].r <= r) return tr[u].sum;
  pushdown(u);
  int mid = tr[u].l + tr[u].r >> 1;
  long res = 0;
  if (l <= mid) res = (res + query(u << 1, l, r)) % P;
  if (r > mid) res = (res + query(u << 1 | 1, l, r)) % P;
  return res;
}

void update_path(int u, int v, long k) {
  while (top[u] != top[v]) {
    if (dep[top[u]] < dep[top[v]]) swap(u, v);
    update(1, id[top[u]], id[u], k);
    u = fa[top[u]];
  }
  if (dep[u] < dep[v]) swap(u, v);
  update(1, id[v], id[u], k);
}

long query_path(int u, int v) {
  long res = 0;
  while (top[u] != top[v]) {
    if (dep[top[u]] < dep[top[v]]) swap(u, v);
    res = (res + query(1, id[top[u]], id[u])) % P;
    u = fa[top[u]];
  }
  if (dep[u] < dep[v]) swap(u, v);
  res = (res + query(1, id[v], id[u])) % P;
  return res;
}

int main() {
  memset(h, -1, sizeof h);
  scanf("%d%d%d%d", &n, &m, &rt, &P);
  for (int i = 1; i <= n; i++) scanf("%ld", &w[i]);
  for (int i = 1; i < n; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    add(a, b), add(b, a);
  }

  dfs1(rt, rt, 0);
  dfs2(rt, rt);
  build(1, 1, n);

  while (m--) {
    int t, u, v;
    long k;
    scanf("%d%d", &t, &u);
    if (t == 1) {
      scanf("%d%ld", &v, &k);
      update_path(u, v, k);
    } else if (t == 2) {
      scanf("%d", &v);
      printf("%ld\n", query_path(u, v));
    } else if (t == 3) {
      scanf("%ld", &k);
      update(1, id[u], id[u] + sz[u] - 1, k);
    } else printf("%ld\n", query(1, id[u], id[u] + sz[u] - 1));
  }
}