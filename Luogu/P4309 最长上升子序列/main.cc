#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int n, idx;
struct Node {
  int l, r;
  int len, maxl, val;
  int sz;
} tr[N];
int root;
int x, y, z;

void pushup(int u) {
  tr[u].sz = tr[tr[u].l].sz + tr[tr[u].r].sz + 1;
  tr[u].maxl = max(tr[u].len, max(tr[tr[u].l].maxl, tr[tr[u].r].maxl));
}

int newnode(int len) {
  tr[++idx] = {0, 0, len, len, rand(), 1};
  return idx;
}

void split(int u, int sz, int &x, int &y) {
  if (!u) {
    x = y = 0;
    return;
  }
  if (sz <= tr[tr[u].l].sz) {
    split(tr[u].l, sz, x, tr[u].l);
    y = u;
  } else {
    split(tr[u].r, sz - tr[tr[u].l].sz - 1, tr[u].r, y);
    x = u;
  }
  pushup(u);
}

int merge(int x, int y) {
  if (!x || !y) return x ^ y;
  if (tr[x].val <= tr[y].val) {
    tr[x].r = merge(tr[x].r, y);
    pushup(x);
    return x;
  } else {
    tr[y].l = merge(x, tr[y].l);
    pushup(y);
    return y;
  }
}

int insert(int pos) {
  split(root, pos, x, z);
  y = newnode(tr[x].maxl + 1);
  root = merge(merge(x, y), z);
  return tr[root].maxl;
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int pos;
    scanf("%d", &pos);
    printf("%d\n", insert(pos));
  }
}