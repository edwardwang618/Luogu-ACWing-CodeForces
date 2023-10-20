#include <iostream>
#include <string>
using namespace std;

namespace {

const int N = 2e5 + 10;
int n, m;

struct Node {
#define lc(p) tr[p].l
#define rc(p) tr[p].r
#define key(p) tr[p].key
#define sz(p) tr[p].sz
#define m(p) tr[p].m
#define add(p) tr[p].add
  int l, r;
  int key, val;
  int sz, m;
  int add;
  bool rev;
} tr[N];
int root, idx;
int x, y, z, y1, y2;

int get_node(int key) {
  tr[++idx] = {0, 0, key, rand(), 1, key, 0, false};
  return idx;
}

void pushup(int p) {
  sz(p) = sz(lc(p)) + sz(rc(p)) + 1;
  m(p) = key(p);
  if (lc(p)) m(p) = min(m(p), m(lc(p)));
  if (rc(p)) m(p) = min(m(p), m(rc(p)));
}

void pushdown(int p) {
  if (add(p)) {
    int a = add(p);
    add(lc(p)) += a, m(lc(p)) += a, key(lc(p)) += a;
    add(rc(p)) += a, m(rc(p)) += a, key(rc(p)) += a;
    add(p) = 0;
  }
  if (tr[p].rev) {
    swap(lc(p), rc(p));
    tr[lc(p)].rev ^= 1, tr[rc(p)].rev ^= 1;
    tr[p].rev = false;
  }
}

int merge(int x, int y) {
  if (!x || !y) return x | y;
  if (tr[x].val > tr[y].val) {
    pushdown(x);
    rc(x) = merge(rc(x), y);
    pushup(x);
    return x;
  } else {
    pushdown(y);
    lc(y) = merge(x, lc(y));
    pushup(y);
    return y;
  }
}

void split(int p, int sz, int &x, int &y) {
  if (!p)
    x = y = 0;
  else {
    pushdown(p);
    if (sz > sz(lc(p))) {
      x = p;
      split(rc(p), sz - sz(lc(p)) - 1, rc(p), y);
    } else {
      y = p;
      split(lc(p), sz, x, lc(p));
    }

    pushup(p);
  }
}

void insert(int pos, int v) {
  split(root, pos, x, z);
  y = get_node(v);
  root = merge(merge(x, y), z);
}

void add_to(int l, int r, int d) {
  split(root, l - 1, x, z);
  split(z, r - l + 1, y, z);
  add(y) += d, m(y) += d, key(y) += d;
  root = merge(merge(x, y), z);
}

void reverse(int l, int r) {
  split(root, l - 1, x, z);
  split(z, r - l + 1, y, z);
  tr[y].rev ^= 1;
  root = merge(merge(x, y), z);
}

void revolve(int l, int r, int t) {
  t %= r - l + 1;
  split(root, l - 1, x, z);
  split(z, r - l + 1, y, z);
  split(y, r - l + 1 - t, y1, y2);
  root = merge(merge(x, y2), merge(y1, z));
}

void remove(int l) {
  split(root, l - 1, x, z);
  split(z, 1, y, z);
  root = merge(x, z);
}

int get_min(int l, int r) {
  split(root, l - 1, x, z);
  split(z, r - l + 1, y, z);
  int res = m(y);
  root = merge(merge(x, y), z);
  return res;
}
}  // namespace

int main() {
  scanf("%d", &n);
  for (int i = 1, x; i <= n; i++) {
    scanf("%d", &x);
    insert(i - 1, x);
  }
  scanf("%d", &m);
  string op;
  int l, r, d;
  while (m--) {
    cin >> op;
    if (op == "ADD") {
      scanf("%d%d%d", &l, &r, &d);
      add_to(l, r, d);
    } else if (op == "REVERSE") {
      scanf("%d%d", &l, &r);
      reverse(l, r);
    } else if (op == "REVOLVE") {
      scanf("%d%d%d", &l, &r, &d);
      revolve(l, r, d);
    } else if (op == "INSERT") {
      scanf("%d%d", &l, &d);
      insert(l, d);
    } else if (op == "DELETE") {
      scanf("%d", &l);
      remove(l);
    } else {
      scanf("%d%d", &l, &r);
      printf("%d\n", get_min(l, r));
    }
  }
}