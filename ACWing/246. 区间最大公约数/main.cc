#include <iostream>
using namespace std;

using ll = long long;
const int N = 500010;
int n, m;
ll a[N];
struct Node {
  int l, r;
  ll sum, d;
} tr[4 * N];

ll gcd(ll a, ll b) {
  while (b) {
    a %= b;
    swap(a, b);
  }
  return a;
}

void pushup(Node &u, Node &l, Node &r) {
  u.sum = l.sum + r.sum;
  u.d = gcd(l.d, r.d);
}

void pushup(int u) { pushup(tr[u], tr[u << 1], tr[u << 1 | 1]); }

void build(int u, int l, int r) {
  if (l == r) {
    ll b = a[l] - a[l - 1];
    tr[u] = {l, r, b, b};
  } else {
    tr[u] = {l, r};
    int mid = l + r >> 1;
    build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
    pushup(u);
  }
}

void modify(int u, int x, long v) {
  if (tr[u].l == x && tr[u].r == x) {
    ll b = tr[u].sum + v;
    tr[u] = {x, x, b, b};
  } else {
    int mid = tr[u].l + tr[u].r >> 1;
    if (x <= mid) modify(u << 1, x, v);
    else modify(u << 1 | 1, x, v);

    pushup(u);
  }
}

Node query(int u, int l, int r) {
  if (l <= tr[u].l && tr[u].r <= r) return tr[u];
  else {
    int mid = tr[u].l + tr[u].r >> 1;
    if (r <= mid) return query(u << 1, l, r);
    else if (l > mid) return query(u << 1 | 1, l, r);
    else {
      auto left = query(u << 1, l, r), right = query(u << 1 | 1, l, r);
      Node res;
      pushup(res, left, right);
      return res;
    }
  }
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);

  build(1, 1, n);

  int l, r;
  ll d;
  char op[2];
  while (m--) {
    scanf("%s%d%d", op, &l, &r);
    if (op[0] == 'Q') {
      Node left = query(1, 1, l), right;
      if (l + 1 <= r) right = query(1, l + 1, r);
      else right.d = 0;
      printf("%lld\n", abs(gcd(left.sum, right.d)));
    } else {
      scanf("%lld", &d);
      modify(1, l, d);
      if (r + 1 <= n) modify(1, r + 1, -d);
    }
  }
}