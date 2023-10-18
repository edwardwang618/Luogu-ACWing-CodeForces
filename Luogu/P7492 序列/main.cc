#include <iostream>
using namespace std;
using ll = long long;

const int N = 1e5 + 10;
int n, m;
ll a[N];
struct Node {
  int l, r;
  ll lsum, rsum, msum, sum, andsum;
} tr[N << 2];

void pushup(Node& u, Node& l, Node& r) {
  u.sum = l.sum + r.sum;
  u.lsum = max(l.lsum, l.sum + r.lsum);
  u.rsum = max(r.rsum, r.sum + l.rsum);
  u.msum = max(max(l.msum, r.msum), l.rsum + r.lsum);
  u.andsum = l.andsum & r.andsum;
}

void pushup(int u) { pushup(tr[u], tr[u << 1], tr[u << 1 | 1]); }

void build(int u, int l, int r) {
  tr[u] = {l, r};
  if (l == r) {
    tr[u].lsum = tr[u].rsum = tr[u].msum = tr[u].sum = tr[u].andsum = a[l];
    return;
  }

  int mid = l + r >> 1;
  build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
  pushup(u);
}

Node query(int u, int l, int r) {
  if (l <= tr[u].l && tr[u].r <= r) return tr[u];
  int mid = tr[u].l + tr[u].r >> 1;
  if (r <= mid) return query(u << 1, l, r);
  if (l > mid) return query(u << 1 | 1, l, r);
  Node res, left = query(u << 1, l, r), right = query(u << 1 | 1, l, r);
  pushup(res, left, right);
  return res;
}

void modify(int u, int l, int r, ll x) {
  if (tr[u].l > r || tr[u].r < l) return;
  if ((tr[u].andsum & x) == x) return;
  if (tr[u].l == tr[u].r) {
    tr[u].andsum |= x;
    tr[u].lsum = tr[u].rsum = tr[u].msum = tr[u].sum = tr[u].andsum;
    return;
  }

  int mid = tr[u].l + tr[u].r >> 1;
  if (l <= mid) modify(u << 1, l, r, x);
  if (r > mid) modify(u << 1 | 1, l, r, x);
  pushup(u);
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
  build(1, 1, n);
  while (m--) {
    int op, l, r;
    ll x;
    scanf("%d%d%d", &op, &l, &r);
    if (op == 1)
      printf("%lld\n", max(0ll, query(1, l, r).msum));
    else {
      scanf("%lld", &x);
      modify(1, l, r, x);
    }
  }
}