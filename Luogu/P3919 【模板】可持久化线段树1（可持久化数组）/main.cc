#include <algorithm>
#include <iostream>
using namespace std;

const int N = 1e6 + 10;
int n, m;
int a[N];
struct Node {
  int l, r, v;
} tr[(N << 2) + N * 20];
int root[N], idx;

int build(int l, int r) {
  int p = ++idx;
  if (l == r) {
    tr[p].v = a[l];
    return p;
  }

  int mid = l + r >> 1;
  tr[p].l = build(l, mid), tr[p].r = build(mid + 1, r);
  return p;
}

int update(int p, int l, int r, int k, int v) {
  int q = ++idx;
  tr[q] = tr[p];
  if (l == r) {
    tr[q].v = v;
    return q;
  }

  int mid = l + r >> 1;
  if (k <= mid) tr[q].l = update(tr[q].l, l, mid, k, v);
  else tr[q].r = update(tr[q].r, mid + 1, r, k, v);
  
  return q;
}

int query(int p, int l, int r, int k) {
  if (l == r) return tr[p].v;
  int mid = l + r >> 1;
  if (k <= mid) return query(tr[p].l, l, mid, k);
  else return query(tr[p].r, mid + 1, r, k);
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

  root[0] = build(1, n);
  for (int i = 1; i <= m; i++) {
    int vi, op, loc, val;
    scanf("%d%d%d", &vi, &op, &loc);
    if (op == 1) {
      scanf("%d", &val);
      root[i] = update(root[vi], 1, n, loc, val);
    } else {
      printf("%d\n", query(root[vi], 1, n, loc));
      root[i] = root[vi];
    }
  }
}