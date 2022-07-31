#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int n;
struct Node {
  int l, r;
  char ch;
} tr[(N << 2) + N * 17];
int root[N], idx, len[N], ver;

int build(int l, int r) {
  int p = ++idx;
  if (l == r) return p;
  int mid = l + r >> 1;
  tr[p].l = build(l, mid), tr[p].r = build(mid + 1, r);
  return p;
}

int update(int p, int l, int r, int k, char ch) {
  int q = ++idx;
  tr[q] = tr[p];

  if (l == r) tr[q].ch = ch;
  else {
    int mid = l + r >> 1;
    if (k <= mid) tr[q].l = update(tr[q].l, l, mid, k, ch);
    else tr[q].r = update(tr[q].r, mid + 1, r, k, ch);
  }

  return q;
}

char query(int p, int l, int r, int k) {
  if (l == r) return tr[p].ch;
  int mid = l + r >> 1;
  if (k <= mid) return query(tr[p].l, l, mid, k);
  else return query(tr[p].r, mid + 1, r, k);
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    char op, ch;
    int x;
    cin >> op;
    if (op == 'T') {
      cin >> ch;
      ver++;
      len[ver] = len[ver - 1] + 1;
      root[ver] = update(root[ver - 1], 1, n, len[ver], ch);
    } else {
      cin >> x;
      if (op == 'U') {
        ver++;
        root[ver] = root[ver - x - 1];
        len[ver] = len[ver - x - 1];
      } else cout << query(root[ver], 1, n, x) << '\n';
    }
  }
}