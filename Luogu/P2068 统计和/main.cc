#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int n, m;
struct Node {
  int l, r;
  long sum;
} tr[N << 2];

void pushup(int u) {
  tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
}

void build(int u, int l, int r) {
  tr[u] = {l, r, 0};
  if (l == r) return;

  int mid = l + r >> 1;
  build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
}

void add(int u, int k, long x) {
  if (k <= tr[u].l && tr[u].r <= k) {
    tr[u].sum += x;
    return;
  }

  int mid = tr[u].l + tr[u].r >> 1;
  if (k <= mid) add(u << 1, k, x);
  else add(u << 1 | 1, k, x);
  pushup(u);
}

long query(int u, int l, int r) {
  if (l <= tr[u].l && tr[u].r <= r) return tr[u].sum;
  int mid = tr[u].l + tr[u].r >> 1;
  long res = 0;
  if (l <= mid) res += query(u << 1, l, r);
  if (r > mid) res += query(u << 1 | 1, l, r);
  return res;
}

int main() {
  scanf("%d%d", &n, &m);
  build(1, 1, n);
  while (m--) {
    char ch;
    cin >> ch;
    if (ch == 'x') {
      int k, x;
      scanf("%d%d", &k, &x);
      add(1, k, x);
    } else {
      int l, r;
      scanf("%d%d", &l, &r);
      printf("%ld\n", query(1, l, r));
    }
  }
}