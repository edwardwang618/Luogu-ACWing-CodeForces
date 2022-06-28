#include <iostream>
#include <cstring>
using namespace std;

const int N = 1e5 + 10;
int n, m;
int h[N], e[N], ne[N], idx;
int dep[N], sz[N], top[N], fa[N], son[N];
int id[N], cnt;
struct Tree {
    int l, r, flag, sum;
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
  id[u] = ++cnt, top[u] = t;
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
  if (root.flag != -1) {
    l.sum = root.flag * (l.r - l.l + 1);
    r.sum = root.flag * (r.r - r.l + 1);
    l.flag = r.flag = root.flag;
    root.flag = -1;
  }
}

void build(int u, int l, int r) {
  tr[u] = {l, r, -1, 0};
  if (l == r) return;
  int mid = l + r >> 1;
  build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
}

void update(int u, int l, int r, int k) {
  if (l <= tr[u].l && tr[u].r <= r) {
    tr[u].flag = k;
    tr[u].sum = k * (tr[u].r - tr[u].l + 1);
    return;
  }

  pushdown(u);
  int mid = tr[u].l + tr[u].r >> 1;
  if (l <= mid) update(u << 1, l, r, k);
  if (r > mid) update(u << 1 | 1, l, r, k);
  pushup(u);
}

void update_path(int u, int v, int k) {
  while (top[u] != top[v]) {
    if (dep[top[u]] < dep[top[v]]) swap(u, v);
    update(1, id[top[u]], id[u], k);
    u = fa[top[u]];
  }
  if (dep[u] < dep[v]) swap(u, v);
  update(1, id[v], id[u], k);
}

void update_tree(int u, int k) {
  update(1, id[u], id[u] + sz[u] - 1, k);
}

int main() {
  memset(h, -1, sizeof h);
  scanf("%d", &n);
  for (int i = 2; i <= n; i++) {
    int p;
    scanf("%d", &p);
    p++;
    add(p, i);
    fa[i] = p;
  }
  dfs1(1, 1);
  dfs2(1, 1);
  build(1, 1, n);

  scanf("%d", &m);
  while (m--) {
    char op[20];
    int u;
    scanf("%s%d", op, &u);
    u++;
    if (!strcmp(op, "install")) {
      int t = tr[1].sum;
      update_path(1, u, 1);
      printf("%d\n", tr[1].sum - t);
    } else {
      int t = tr[1].sum;
      update_tree(u, 0);
      printf("%d\n", t - tr[1].sum);
    }
  }
}