#include <iostream>
#include <cstring>
using namespace std;

const int N = 4e6 + 10, INF = 1e9;
int n, m;
struct Node {
#define lc(u) tr[u].l
#define rc(u) tr[u].r
#define sz(u) tr[u].sz
  int l, r, v, sz, rnd;
  int sum, ls, rs, ms;
  bool rev, same;
  void init(int _v) {
    l = r = 0;
    v = _v;
    rev = same = 0;
    sz = 1, sum = ms = v;
    ls = rs = max(0, v);
    rnd = rand();
  }
} tr[N];
int root, nodes[N], tt;
int x, y, z;
int w[N];

void pushup(int x) {
  auto &u = tr[x], &l = tr[lc(x)], &r = tr[rc(x)];
  u.sz = l.sz + r.sz + 1;
  u.sum = l.sum + r.sum + u.v;
  u.ls = max(l.ls, l.sum + u.v + r.ls);
  u.rs = max(r.rs, r.sum + u.v + l.rs);
  u.ms = max(max(l.ms, r.ms), l.rs + u.v + r.ls);
}

void pushdown(int x) {
  auto &u = tr[x], &l = tr[lc(x)], &r = tr[rc(x)];
  if (u.same) {
    u.same = u.rev = 0;
    if (u.l) l.same = 1, l.v = u.v, l.sum = l.v * l.sz;
    if (u.r) r.same = 1, r.v = u.v, r.sum = r.v * r.sz;
    if (u.v > 0) {
      if (u.l) l.ms = l.ls = l.rs = l.sum;
      if (u.r) r.ms = r.ls = r.rs = r.sum;
    } else {
      if (u.l) l.ms = l.v, l.ls = l.rs = 0;
      if (u.r) r.ms = r.v, r.ls = r.rs = 0;
    }
  } else if (u.rev) {
    u.rev = 0, l.rev ^= 1, r.rev ^= 1;
    swap(l.ls, l.rs), swap(r.ls, r.rs);
    swap(l.l, l.r), swap(r.l, r.r);
  }
}

int build(int l, int r) {
  int mid = l + r >> 1;
  int u = nodes[tt--];
  tr[u].init(w[mid]);
  if (l < mid) lc(u) = build(l, mid - 1);
  if (r > mid) rc(u) = build(mid + 1, r);
  pushup(u);
  return u;
}

void split(int u, int sz, int &x, int &y) {
  if (!u) x = y = 0;
  else {
    pushdown(u);
    if (sz(lc(u)) < sz) {
      x = u;
      split(rc(u), sz - sz(lc(u)) - 1, rc(u), y);
    } else {
      y = u;
      split(lc(u), sz, x, lc(u));
    }
    pushup(u);
  }
}

int merge(int x, int y) {
  if (!x || !y) return x | y;
  if (tr[x].rnd > tr[y].rnd) {
    pushdown(x);
    rc(x) = merge(rc(x), y);
    pushup(x);
    return x;
  } else {
    pushdown(y);
    lc(y) = merge(x, lc(y));
    pushup(y);
    return y;
  }
}

void dfs(int u) {
  if (!u) return;
  dfs(lc(u));
  dfs(rc(u));
  nodes[++tt] = u;
}

int main() {
  for (int i = 1; i < N; i++) nodes[++tt] = i;
  tr[0].ms = -INF;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &w[i]);
  root = build(1, n);

  char op[20];
  while (m--) {
    scanf("%s", op);
    if (!strcmp(op, "INSERT")) {
      int posi, tot;
      scanf("%d%d", &posi, &tot);
      for (int i = 1; i <= tot; i++) scanf("%d", &w[i]);
      split(root, posi, x, y);
      int u = build(1, tot);
      root = merge(merge(x, u), y);
    } else if (!strcmp(op, "DELETE")) {
      int posi, tot;
      scanf("%d%d", &posi, &tot);
      split(root, posi - 1, x, y);
      split(y, tot, y, z);
      dfs(y);
      root = merge(x, z);
    } else if (!strcmp(op, "MAKE-SAME")) {
      int posi, tot, c;
      scanf("%d%d%d", &posi, &tot, &c);
      split(root, posi - 1, x, y);
      split(y, tot, y, z);
      auto &u = tr[y];
      u.same = 1, u.v = c, u.sum = c * u.sz;
      if (c > 0)
        u.ms = u.ls = u.rs = u.sum;
      else
        u.ms = c, u.ls = u.rs = 0;
      root = merge(merge(x, y), z);
    } else if (!strcmp(op, "REVERSE")) {
      int posi, tot;
      scanf("%d%d", &posi, &tot);
      split(root, posi - 1, x, y);
      split(y, tot, y, z);
      auto &u = tr[y];
      u.rev ^= 1;
      swap(u.l, u.r);
      swap(u.ls, u.rs);
      root = merge(merge(x, y), z);
    } else if (!strcmp(op, "GET-SUM")) {
      int posi, tot;
      scanf("%d%d", &posi, &tot);
      split(root, posi - 1, x, y);
      split(y, tot, y, z);
      printf("%d\n", tr[y].sum);
      root = merge(merge(x, y), z);
    } else
      printf("%d\n", tr[root].ms);
  }
}