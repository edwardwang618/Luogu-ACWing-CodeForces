#include <iostream>
using namespace std;

const int N = 1e5 + 10, INF = 1e9;
int n, m;
int a[N];

namespace FHQ {

struct Node {
#define lc(u) tr[u].l
#define rc(u) tr[u].r
#define val(u) tr[u].val
#define sz(u) tr[u].sz
  int l, r;
  int val, sz;
  int rnd;
} tr[N * 21];
int idx;
int get_node(int v) {
  tr[++idx] = {0, 0, v, 1, rand()};
  return idx;
}

void pushup(int u) { sz(u) = sz(lc(u)) + sz(rc(u)) + 1; }

void split(int u, int val, int &x, int &y) {
  if (!u) x = y = 0;
  else {
    if (val < val(u)) {
      y = u;
      split(lc(u), val, x, lc(u));
      pushup(y);
    } else {
      x = u;
      split(rc(u), val, rc(u), y);
      pushup(x);
    }
  }
}

int merge(int x, int y) {
  if (!x || !y) return x | y;
  else {
    if (tr[x].rnd > tr[y].rnd) {
      rc(x) = merge(rc(x), y);
      pushup(x);
      return x;
    } else {
      lc(y) = merge(x, lc(y));
      pushup(y);
      return y;
    }
  }
}

struct FHQ {
  int root;
  
  void insert(int v) {
    int x, y, z;
    split(root, v - 1, x, z);
    y = get_node(v);
    root = merge(merge(x, y), z);
  }
  
  void modify(int w, int v) {
    int x, y, z;
    split(root, w - 1, x, z);
    split(z, w, y, z);
    y = merge(lc(y), rc(y));
    root = merge(merge(x, y), z);
    insert(v);
  }

  int get_less(int v) {
    int x, y;
    split(root, v - 1, x, y);
    int res = sz(x);
    root = merge(x, y);
    return res;
  }

  int get_prev(int v) {
    int u = root, res = -INF;
    while (u) {
      if (v > val(u)) res = max(res, val(u)), u = rc(u);
      else u = lc(u);
    }
    return res;
  }

  int get_next(int v) {
    int u = root, res = INF;
    while (u) {
      if (v < val(u)) res = min(res, val(u)), u = lc(u);
      else u = rc(u);
    }
    return res;
  }
};

}  // namespace FHQ

namespace SegTree {

struct Node {
  int l, r;
  FHQ::FHQ fhq;
} tr[N << 2];

void build(int u, int l, int r) {
  tr[u] = {l, r};
  for (int i = l; i <= r; i++) tr[u].fhq.insert(a[i]);
  if (l == r) return;

  int mid = l + r >> 1;
  build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
}

int get_less(int u, int l, int r, int x) {
  if (l <= tr[u].l && tr[u].r <= r) return tr[u].fhq.get_less(x);
  int mid = tr[u].l + tr[u].r >> 1;
  int res = 0;
  if (l <= mid) res += get_less(u << 1, l, r, x);
  if (r > mid) res += get_less(u << 1 | 1, l, r, x);
  return res;
}

int get_key_from_rank(int lq, int rq, int rk) {
  int l = 0, r = 1e8;
  while (l < r) {
    int mid = l + r + 1 >> 1;
    if (get_less(1, lq, rq, mid) + 1 <= rk) l = mid;
    else r = mid - 1;
  }

  return l;
}

void modify(int u, int pos, int x) {
  if (pos < tr[u].l || pos > tr[u].r) return;
  tr[u].fhq.modify(a[pos], x);
  int mid = tr[u].l + tr[u].r >> 1;
  if (pos <= mid) modify(u << 1, pos, x);
  else modify(u << 1 | 1, pos, x);
}

int get_prev(int u, int l, int r, int x) {
  if (l <= tr[u].l && tr[u].r <= r) return tr[u].fhq.get_prev(x);
  int mid = tr[u].l + tr[u].r >> 1;
  int res = -INF;
  if (l <= mid) res = max(res, get_prev(u << 1, l, r, x));
  if (r > mid) res = max(res, get_prev(u << 1 | 1, l, r, x));
  return res;
}

int get_next(int u, int l, int r, int x) {
  if (l <= tr[u].l && tr[u].r <= r) return tr[u].fhq.get_next(x);
  int mid = tr[u].l + tr[u].r >> 1;
  int res = INF;
  if (l <= mid) res = min(res, get_next(u << 1, l, r, x));
  if (r > mid) res = min(res, get_next(u << 1 | 1, l, r, x));
  return res;
}

}  // namespace SegTree

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  SegTree::build(1, 1, n);
  while (m--) {
    int op, l, r, pos, x;
    scanf("%d", &op);
    if (op == 1 || op == 2 || op == 4 || op == 5) scanf("%d%d%d", &l, &r, &x);
    else scanf("%d%d", &pos, &x);

    if (op == 1) printf("%d\n", SegTree::get_less(1, l, r, x) + 1);
    else if (op == 2) printf("%d\n", SegTree::get_key_from_rank(l, r, x));
    else if (op == 3) {
      SegTree::modify(1, pos, x);
      a[pos] = x;
    } else if (op == 4) printf("%d\n", SegTree::get_prev(1, l, r, x));
    else printf("%d\n", SegTree::get_next(1, l, r, x));
  }
}