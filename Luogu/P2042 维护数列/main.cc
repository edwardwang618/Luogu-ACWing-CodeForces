#include <iostream>
#include <string>
using namespace std;

namespace {
const int N = 5e5 + 10, INF = 2e9;
int n, m;
struct Node {
#define lc(u) tr[u].l
#define rc(u) tr[u].r
#define sz(u) tr[u].sz
  int l, r;
  int v, sz;
  int sum, ls, rs, ms;
  bool same, rev;
  int rnd;
  void init(int _v) {
    l = r = 0;
    v = _v, sz = 1;
    ls = rs = max(0, _v);
    sum = ms = _v;
    rev = same = false;
    rnd = rand();
  }
} tr[N];

int root, nodes[N], tt;
int x, y, z, y1, y2;
int w[N];
int posi, tot;

void pushup(int x) {
  auto &u = tr[x], &l = tr[lc(x)], &r = tr[rc(x)];
  u.sz = l.sz + r.sz + 1;
  u.sum = l.sum + r.sum + u.v;
  u.ls = max(l.ls, l.sum + u.v + r.ls);
  u.rs = max(r.rs, r.sum + u.v + l.rs);
  int ms = -INF;
  if (u.l) ms = max(ms, l.ms);
  if (u.r) ms = max(ms, r.ms);
  u.ms = max(ms, l.rs + u.v + r.ls);
}

void pushdown(int x) {
  auto &u = tr[x], &l = tr[lc(x)], &r = tr[rc(x)];
  if (u.same) {
    u.same = u.rev = 0;
    if (u.l) {
      l.same = 1, l.rev = 0;
      l.v = u.v, l.sum = l.v * l.sz;
      if (u.v > 0) l.ls = l.rs = l.ms = l.sum;
      else {
        l.ls = l.rs = 0;
        l.ms = l.v;
      }
    }
    if (u.r) {
      r.same = 1, r.rev = 0;
      r.v = u.v, r.sum = r.v * r.sz;
      if (u.v > 0) r.ls = r.rs = r.ms = r.sum;
      else {
        r.ls = r.rs = 0;
        r.ms = r.v;
      }
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
    if (sz <= sz(lc(u))) {
      y = u;
      split(lc(u), sz, x, lc(y));
    } else {
      x = u;
      split(rc(u), sz - sz(lc(u)) - 1, rc(u), y);
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

void Insert() {
  scanf("%d%d", &posi, &tot);
  for (int i = 1; i <= tot; i++) scanf("%d", &w[i]);
  int u = build(1, tot);
  split(root, posi, x, y);
  root = merge(merge(x, u), y);
}

void Delete() {
  scanf("%d%d", &posi, &tot);
  split(root, posi - 1, x, z);
  split(z, tot, y, z);
  dfs(y);
  root = merge(x, z);
}

void MakeSame() {
  int c;
  scanf("%d%d%d", &posi, &tot, &c);
  split(root, posi - 1, x, z);
  split(z, tot, y, z);
  auto &u = tr[y];
  u.same = 1, u.v = c, u.sum = c * u.sz;
  if (c > 0) u.ms = u.ls = u.rs = u.sum;
  else u.ms = c, u.ls = u.rs = 0;
  root = merge(merge(x, y), z);
}

void Reverse() {
  scanf("%d%d", &posi, &tot);
  split(root, posi - 1, x, z);
  split(z, tot, y, z);
  auto &u = tr[y];
  u.rev = 1;
  swap(u.l, u.r);
  swap(u.ls, u.rs);
  root = merge(merge(x, y), z);
}

void GetSum() {
  scanf("%d%d", &posi, &tot);
  split(root, posi - 1, x, z);
  split(z, tot, y, z);
  printf("%d\n", tr[y].sum);
  root = merge(merge(x, y), z);
}

void MaxSum() { printf("%d\n", tr[root].ms); }

}  // namespace

int main() {
  for (int i = 1; i < N; i++) nodes[++tt] = i;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &w[i]);
  root = build(1, n);

  string op;
  while (m--) {
    cin >> op;
    if (op == "INSERT") Insert();
    else if (op == "DELETE") Delete();
    else if (op == "MAKE-SAME") MakeSame();
    else if (op == "REVERSE") Reverse();
    else if (op == "GET-SUM") GetSum();
    else MaxSum();
  }
}