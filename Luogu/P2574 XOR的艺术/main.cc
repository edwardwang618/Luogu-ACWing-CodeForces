#include <iostream>
using namespace std;

const int N = 2e5 + 10;
int n, m;
char s[N];
int a[N];
struct Node {
  int l, r;
  int sum;
  bool b;
} tr[N << 2];

void pushup(int u) {
  tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
}

void pushdown(int u) {
  auto &l = tr[u << 1], &r = tr[u << 1 | 1];
  if (tr[u].b) {
	l.sum = l.r - l.l + 1 - l.sum;
	r.sum = r.r - r.l + 1 - r.sum;
	l.b ^= 1;
	r.b ^= 1;
	tr[u].b = false;
  }
}

void build(int u, int l, int r) {
  tr[u] = {l, r, 0, false};
  if (l == r) {
	tr[u].sum = a[l];
	return;
  }

  int mid = l + r >> 1;
  build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
  pushup(u);
}

void modify(int u, int l, int r) {
  if (l <= tr[u].l && tr[u].r <= r) {
	tr[u].sum = tr[u].r - tr[u].l + 1 - tr[u].sum;
	tr[u].b ^= 1;
	return;
  }

  pushdown(u);
  int mid = tr[u].l + tr[u].r >> 1;
  if (l <= mid) modify(u << 1, l, r);
  if (r > mid) modify(u << 1 | 1, l, r);
  pushup(u);
}

int sum(int u, int l, int r) {
  if (l <= tr[u].l && tr[u].r <= r) return tr[u].sum;
  pushdown(u);
  int mid = tr[u].l + tr[u].r >> 1;
  int res = 0;
  if (l <= mid) res = sum(u << 1, l, r);
  if (r > mid) res += sum(u << 1 | 1, l, r);
  return res;
}

int main() {
  scanf("%d%d", &n, &m);
  scanf("%s", s + 1);
  for (int i = 1; i <= n; i++) a[i] = s[i] - '0';
  build(1, 1, n);
  while (m--) {
	int op, l, r;
	scanf("%d%d%d", &op, &l, &r);
	if (op == 0) modify(1, l, r);
	else printf("%d\n", sum(1, l, r));
  }
}