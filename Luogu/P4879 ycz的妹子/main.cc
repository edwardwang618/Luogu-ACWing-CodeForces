#include <iostream>
using namespace std;

const int N = 5e5 + 10;
int n, m;
long a[N];
struct Node {
  int l, r;
  long sum;
  int cnt;
} tr[N << 2];

void pushup(int u) {
  tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
  tr[u].cnt = tr[u << 1].cnt + tr[u << 1 | 1].cnt;
}

void build(int u, int l, int r) {
  tr[u].l = l, tr[u].r = r;
  if (l == r) {
	if (l <= n) tr[u].sum = a[l], tr[u].cnt = 1;
	else tr[u].sum = tr[u].cnt = 0;
	return;
  }

  int mid = (l + r) >> 1;
  build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
  pushup(u);
}

void modify(int u, int k, long x, char op) {
  if (tr[u].l == tr[u].r) {
	if (op == 'C') tr[u].sum -= x;
	else tr[u].sum = x, tr[u].cnt = 1;
	return;
  }

  int mid = tr[u].l + tr[u].r >> 1;
  if (k <= mid) modify(u << 1, k, x, op);
  else modify(u << 1 | 1, k, x, op);
  pushup(u);
}

void remove(int u, int k) {
  if (tr[u].l == tr[u].r) {
	tr[u].sum = tr[u].cnt = 0;
	return;
  }

  if (k <= tr[u << 1].cnt) remove(u << 1, k);
  else remove(u << 1 | 1, k - tr[u << 1].cnt);
  pushup(u);
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%ld", &a[i]);
  build(1, 1, 5e5);

  while (m--) {
	  char op;
	  cin >> op;
	  int k;
	  long x;
	  if (op == 'C' || op == 'I') {
	    scanf("%d%ld", &k, &x);
	    modify(1, k, x, op);
	  } else if (op == 'D') {
	    scanf("%d", &k);
	    remove(1, k);
	  } else printf("%ld\n", tr[1].sum);
  }
}