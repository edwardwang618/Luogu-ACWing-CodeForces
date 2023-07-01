#include <iostream>
using namespace std;

const int N = 1e5 + 10, INF = 1e9;
int n, m;
int a[N];
namespace Treap {
struct Node {
  int l, r;
  int key, val;
  int sz;
} tr[N * 20];
int idx;

void pushup(int u) {
  tr[u].sz = tr[tr[u].l].sz + tr[tr[u].r].sz + 1;
}

int get_node(int key) {
  tr[++idx] = {0, 0, key, rand(), 1};
  return idx;
}

void zig(int &p) {
  int q = tr[p].l;
  tr[p].l = tr[q].r, tr[q].r = p, p = q;
  pushup(tr[p].r);
}

void zag(int &p) {
  int q = tr[p].r;
  tr[p].r = tr[q].l, tr[q].l = p, p = q;
  pushup(tr[p].l);
}

void insert(int &p, int x) {
  if (!p) {
    p = get_node(x);
    return;
  }

  if (x <= tr[p].key) {
    insert(tr[p].l, x);
    if (tr[tr[p].l].val > tr[p].val) zig(p);
  } else if (x > tr[p].key) {
    insert(tr[p].r, x);
    if (tr[tr[p].r].val > tr[p].val) zag(p);
  }

  pushup(p);
}

void update(int &p, int k, int x) {
  if (k <= tr[tr[p].l].sz) update(tr[p].l, k, x);
  else if (k > tr[tr[p].l].sz + 1) update(tr[p].r, k - tr[tr[p].l].sz - 1, x);
  else tr[p].key = x;
}

int get_prev(int p, int x) {
  if (!p) return -INF;
  if (x <= tr[p].key) return get_prev(tr[p].l, x);
  else return max(tr[p].key, get_prev(tr[p].r, x));
}

int get_next(int p, int x) {
  if (!p) return INF;
  if (x >= tr[p].key) return get_next(tr[p].r, x);
  else return min(tr[p].key, get_next(tr[p].l, x));
}

int get_rank(int p, int x) {
  if (x <= tr[p].key) return count_less(tr[p].l, x);
  else if (x > tr[p].key) return tr[tr[p].l].sz + 1 + count_less(tr[p].r, x);
}
}

namespace SegTree {
struct Node {
  int l, r;
  int root;
} tr[N << 2];

void build(int u, int l, int r) {
  tr[u] = {l, r, Treap::get_node(a[l])};
  if (l == r) return;
  for (int i = l + 1; i <= r; i++) Treap::insert(root, a[i]);
  int mid = l + r >> 1;
  build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
}

void modify(int u, int k, int x) {
  Treap::update(tr[u].root, k, x);
  if (tr[u].l == tr[u].r) return;

  int mid = tr[u].l + tr[u].r >> 1;
  if (k <= mid) modify(u << 1, k, x);
  else modify(u << 1 | 1, k - (tr[u << 1].r - tr[u << 1].l + 1), x);
}

int count_less(int u, int l, int r, int x) {
  if (l <= tr[u].l && tr[u].r <= r) return Treap::count_less(tr[u].root, x);
  int mid = tr[u].l + tr[u].r >> 1;
  int res = 0;
  if (l <= mid) res = count_less(u << 1, l, r, x);
  if (r > mid) res += count_less(u << 1 | 1, l, r, x);
  return res;
}

int get_


}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  SegTree::build(1, l, r);
  while (m--) {
    int op, l, r, k, x;
    scanf("%d", &op);
    if (op == 1 || op == 2 || op == 4 || op == 5) scanf("%d%d", &l, &r);


  }
}