#include <iostream>
#include <cstring>
using namespace std;

const int N = 1e5 + 10, M = N << 1;
int n, m;
int h[N], e[M], ne[M], idx, w[N];
int id[N], nw[N], sz[N], dep[N], fa[N], son[N], top[N], cnt;
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
    l.sum += root.add * (l.r - l.l + 1);
    l.add += root.add;
    r.sum += root.add * (r.r - r.l + 1);
    r.add += root.add;
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

void modify(int u, int l, int r, long k) {
  if (l <= tr[u].l && tr[u].r <= r) {
    tr[u].add += k;
    tr[u].sum += k * (tr[u].r - tr[u].l + 1);
    return;
  }

  pushdown(u);
  int mid = tr[u].l + tr[u].r >> 1;
  if (l <= mid) modify(u << 1, l, r, k);
  if (r > mid) modify(u << 1 | 1, l, r, k);
  pushup(u);
}

long query(int u, int l, int r) {
  if (l <= tr[u].l && tr[u].r <= r) return tr[u].sum;
  pushdown(u);
  long res = 0;
  int mid = tr[u].l + tr[u].r >> 1;
  if (l <= mid) res += query(u << 1, l, r);
  if (r > mid) res += query(u << 1 | 1, l, r);
  return res;
}

long add_to(int u, long k) {
  modify(1, id[u], id[u], k);
}

long add_tree(int u, long k) {
  modify(1, id[u], id[u] + sz[u] - 1, k);
}

long query_path(int u, int v) {
  long res = 0;
  while (top[u] != top[v]) {
    if (dep[top[u]] < dep[top[v]]) swap(u, v);
    res += query(1, id[top[u]], id[u]);
    u = fa[top[u]];
  }

  if (dep[u] < dep[v]) swap(u, v);
  res += query(1, id[v], id[u]);
  return res;
}

int main() {
  memset(h, -1, sizeof h);
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &w[i]);
  for (int i = 1; i < n; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    add(a, b), add(b, a);
  }

  dfs1(1, 1, 0);
  dfs2(1, 1);
  build(1, 1, n);

  while (m--) {
    int op, x, a;
    scanf("%d%d", &op, &x);
    if (op == 1) {
      scanf("%d", &a);
      add_to(x, a);
    } else if (op == 2) {
      scanf("%d", &a);
      add_tree(x, a);
    } else printf("%ld\n", query_path(1, x));
  }
}