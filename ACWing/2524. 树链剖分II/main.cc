#include <iostream>
#include <cstring>
using namespace std;

const int N = 1e5 + 10;
int n, m;
int h[N], e[N], ne[N], idx, w[N];
int id[N], nw[N], cnt;
int dep[N], son[N], top[N], sz[N], fa[N];
int root;
struct Tree {
  int l, r;
  long sum, add;
} tr[N << 2];

void add(int a, int b) {
  e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void dfs1(int u, int depth) {
  dep[u] = depth, sz[u] = 1;
  for (int i = h[u]; ~i; i = ne[i]) {
    int v = e[i];
    dfs1(v, depth + 1);
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
    if (v == son[u]) continue;
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
  int mid = tr[u].l + tr[u].r >> 1;
  long res = 0;
  if (l <= mid) res += query(u << 1, l, r);
  if (r > mid) res += query(u << 1 | 1, l, r);
  return res;
}

void add_path(int u, int v, int k) {
  while (top[u] != top[v]) {
    if (dep[top[u]] < dep[top[v]]) swap(u, v);
    modify(1, id[top[u]], id[u], k);
    u = fa[top[u]];
  }
  if (dep[u] < dep[v]) swap(u, v);
  modify(1, id[v], id[u], k);
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

int lca(int u, int v) {
  while (top[u] != top[v]) {
    if (dep[top[u]] < dep[top[v]]) swap(u, v);
    u = fa[top[u]];
  }
  return dep[u] < dep[v] ? u : v;
}

int get_son(int u, int v) {
  while (top[u] != top[v]) {
    if (fa[top[u]] == v) return top[u];
    u = fa[top[u]];
  }
  return son[v];
}

void add_sub(int u, int k) {
  modify(1, id[u], id[u] + sz[u] - 1, k);
}

void add_tree(int u, int k) {
  if (u == root) modify(1, 1, n, k);
  else if (lca(u, root) != u) modify(1, id[u], id[u] + sz[u] - 1, k);
  else {
    int x = get_son(root, u);
    modify(1, 1, n, k);
    modify(1, id[x], id[x] + sz[x] - 1, -k);
  }
}

long query_tree(int u) {
  if (u == root) return query(1, 1, n);
  if (lca(u, root) != u) return query(1, id[u], id[u] + sz[u] - 1);
  int x = get_son(root, u);
  return query(1, 1, n) - query(1, id[x], id[x] + sz[x] - 1);
}

int main() {
  memset(h, -1, sizeof h);
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%ld", &w[i]);
  for (int i = 2; i <= n; i++) {
    int p;
    scanf("%d", &p);
    add(p, i);
    fa[i] = p;
  }

  dfs1(1, 0);
  dfs2(1, 1);
  build(1, 1, n);

  scanf("%d", &m);
  while (m--) {
    int op, u, v;
    long k;
    scanf("%d%d", &op, &u);
    if (op == 1) {
      root = u;
    } else if (op == 2) {
      scanf("%d%ld", &v, &k);
      add_path(u, v, k);
    } else if (op == 3) {
      scanf("%ld", &k);
      add_tree(u, k);
    } else if (op == 4) {
      scanf("%d", &v);
      printf("%ld\n", query_path(u, v));
    } else printf("%ld\n", query_tree(u));
  }
}