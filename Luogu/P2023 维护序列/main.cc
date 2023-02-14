#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int n, m, P;
int a[N];
struct Node {
  int l, r;
  long sum;
  long mul, add;
} tr[N << 2];

void pushup(int u) {
  tr[u].sum = (tr[u << 1].sum + tr[u << 1 | 1].sum) % P;
}

void update(Node &u, long mul, long add) {
  u.sum = (u.sum * mul + add * (u.r - u.l + 1)) % P;
  u.mul = u.mul * mul % P;
  u.add = (u.add * mul + add) % P;
}

void pushdown(int u) {
  auto &mul = tr[u].mul, &add = tr[u].add;
  update(tr[u << 1], mul, add), update(tr[u << 1 | 1], mul, add);
  mul = 1;
  add = 0;
}

void build(int u, int l, int r) {
  tr[u] = {l, r, 0, 1, 0};
  if (l == r) {
	tr[u].sum = a[l] % P;
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
  int mid = tr[u].l + tr[u].r >> 1;
  long res = 0;
  if (l <= mid) res = query(u << 1, l, r);
  if (r > mid) res = (res + query(u << 1 | 1, l, r)) % P;
  return res;
}

int main() {
  scanf("%d%d", &n, &P);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  build(1, 1, n);
  scanf("%d", &m);
  while (m--) {
	int op, l, r;
	long c;
	scanf("%d%d%d", &op, &l, &r);
	if (op < 3) scanf("%ld", &c);
	if (op == 1) modify(1, l, r, c, 0);
	else if (op == 2) modify(1, l, r, 1, c);
	else printf("%ld\n", query(1, l, r));
  }
}