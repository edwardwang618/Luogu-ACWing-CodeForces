#include <iostream>
#include <cstring>
using namespace std;

const int N = 3e4 + 10, M = N << 1, INF = 1e9;
int n, m;
int h[N], e[M], ne[M], w[N], idx;
int dep[N], sz[N], son[N], fa[N];
int id[N], top[N], nw[N], cnt;
struct Tree {
  int l, r, max, sum;
} tr[N << 2];

void add(int a, int b) {
  e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void dfs1(int u, int from, int depth) {
  sz[u] = 1, dep[u] = depth, fa[u] = from;
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
    if (v != fa[u] && v != son[u]) dfs2(v, v);
  }
}

void pushup(int u) {
  tr[u].max = max(tr[u << 1].max, tr[u << 1 | 1].max);
  tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
}

void build(int u, int l, int r) {
  tr[u] = {l, r, nw[l], nw[l]};
  if (l == r) return;
  int mid = l + r >> 1;
  build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
  pushup(u);
}

void modify(int u, int k, int t) {
  if (tr[u].l == tr[u].r) {
    tr[u].sum = tr[u].max = t;
    return;
  }

  int mid = tr[u].l + tr[u].r >> 1;
  if (k <= mid) modify(u << 1, k, t);
  else modify(u << 1 | 1, k, t);
  pushup(u);
}

int query_max(int u, int l, int r) {
  if (l <= tr[u].l && tr[u].r <= r) return tr[u].max;
  int res = -INF;
  int mid = tr[u].l + tr[u].r >> 1;
  if (l <= mid) res = max(res, query_max(u << 1, l, r));
  if (r > mid) res = max(res, query_max(u << 1 | 1, l, r));
  return res;
}

int query_sum(int u, int l, int r) {
  if (l <= tr[u].l && tr[u].r <= r) return tr[u].sum;
  int res = 0;
  int mid = tr[u].l + tr[u].r >> 1;
  if (l <= mid) res += query_sum(u << 1, l, r);
  if (r > mid) res += query_sum(u << 1 | 1, l, r);
  return res;
}

int qmax(int u, int v) {
  int res = -INF;
  while (top[u] != top[v]) {
    if (dep[top[u]] < dep[top[v]]) swap(u, v);
    res = max(res, query_max(1, id[top[u]], id[u]));
    u = fa[top[u]];
  }
  if (dep[u] < dep[v]) swap(u, v);
  res = max(res, query_max(1, id[v], id[u]));
  return res;
}

int qsum(int u, int v) {
  int res = 0;
  while (top[u] != top[v]) {
    if (dep[top[u]] < dep[top[v]]) swap(u, v);
    res += query_sum(1, id[top[u]], id[u]);
    u = fa[top[u]];
  }
  if (dep[u] < dep[v]) swap(u, v);
  res += query_sum(1, id[v], id[u]);
  return res;
}

int main() {
  memset(h, -1, sizeof h);
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    add(a, b), add(b, a);
  }
  for (int i = 1; i <= n; i++) scanf("%d", &w[i]);

  dfs1(1, -1, 0);
  dfs2(1, 1);
  build(1, 1, n);

  scanf("%d", &m);
  while (m--) {
    char op[6];
    int u, v, t;
    scanf("%s%d", op, &u);
    if (!strcmp(op, "CHANGE")) {
      scanf("%d", &t);
      modify(1, id[u], t);
    } else {
      scanf("%d", &v);
      if (!strcmp(op, "QMAX")) printf("%d\n", qmax(u, v));
      else printf("%d\n", qsum(u, v));
    } 
  }
}