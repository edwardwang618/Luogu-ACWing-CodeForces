#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int n, m;
long p, a[N];
struct Node {
  int l, r;
  long sum;
  long mul, add;
} tr[N << 2];

void pushup(int u) {
  tr[u].sum = (tr[u << 1].sum + tr[u << 1 | 1].sum) % p;
}

void update(Node &u, long mul, long add) {
  u.mul = (u.mul * mul) % p;
  u.add = (u.add * mul + add) % p;
  u.sum = (u.sum * mul + add * (u.r - u.l + 1)) % p;
}

void pushdown(int u) {
  update(tr[u << 1], tr[u].mul, tr[u].add);
  update(tr[u << 1 | 1], tr[u].mul, tr[u].add);
  tr[u].mul = 1, tr[u].add = 0;
}

void build(int u, int l, int r) {
  tr[u] = {l, r, 0, 1, 0};
  if (l == r) {
    tr[u].sum = a[l];
    return;
  }
  int mid = l + r >> 1;
  build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
  pushup(u);
}

void modify(int u, int l, int r, long mul, long add) {
  if (l <= tr[u].l && tr[u].r <= r) {
    update(tr[u], mul, add);
    return;
  }

  pushdown(u);
  int mid = tr[u].l + tr[u].r >> 1;
  if (l <= mid) modify(u << 1, l, r, mul, add);
  if (r > mid) modify(u << 1 | 1, l, r, mul, add);
  pushup(u);
}

long query(int u, int l, int r) {
  if (l <= tr[u].l && tr[u].r <= r) return tr[u].sum;

  pushdown(u);
  long res = 0;
  int mid = tr[u].l + tr[u].r >> 1;
  if (l <= mid) res = (res + query(u << 1, l, r)) % p;
  if (r > mid) res = (res + query(u << 1 | 1, l, r)) % p;
  return res;
}

int main() {
  scanf("%d%d%ld", &n, &m, &p);
  for (int i = 1; i <= n; i++) scanf("%ld", &a[i]);
  build(1, 1, n);
  while (m--) {
    int op, l, r;
    long x;
    scanf("%d%d%d", &op, &l, &r);
    if (op == 1) {
      scanf("%ld", &x);
      modify(1, l, r, x, 0);
    } else if (op == 2) {
      scanf("%ld", &x);
      modify(1, l, r, 1, x);
    } else printf("%ld\n", query(1, l, r));
  }
}