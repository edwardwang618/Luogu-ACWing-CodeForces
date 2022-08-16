#include <iostream>
#include <climits>
using namespace std;

const int N = 5e5 + 10;
int n, root[N], idx;
int x, y, z;
struct Node {
  int l, r;
  int key, val;
  int sz;
} tr[N * 50];

int newnode(int v) {
  int p = ++idx;
  tr[p].key = v;
  tr[p].val = rand();
  tr[p].sz = 1;
  return p;
}

#define pushup(u) tr[u].sz = tr[tr[u].l].sz + tr[tr[u].r].sz + 1

void split(int p, int v, int &x, int &y) {
  if (!p) {
    x = y = 0;
    return;
  }

  if (tr[p].key <= v) {
    x = ++idx;
    tr[x] = tr[p];
    split(tr[x].r, v, tr[x].r, y);
    pushup(x);
  } else {
    y = ++idx;
    tr[y] = tr[p];
    split(tr[y].l, v, x, tr[y].l);
    pushup(y);
  }
}

int merge(int x, int y) {
  if (!x || !y) return x ^ y;
  if (tr[x].val < tr[y].val) {
    tr[x].r = merge(tr[x].r, y);
    pushup(x);
    return x;
  } else {
    tr[y].l = merge(x, tr[y].l);
    pushup(y);
    return y;
  }
}

void insert(int &root, int v) {
  split(root, v, x, y);
  z = newnode(v);
  root = merge(merge(x, z), y);
}

void remove(int &root, int v) {
  split(root, v, x, z);
  split(x, v - 1, x, y);
  y = merge(tr[y].l, tr[y].r);
  root = merge(merge(x, y), z);
}

int get_rank(int &root, int v) {
  split(root, v - 1, x, y);
  int res = tr[x].sz + 1;
  root = merge(x, y);
  return res;
}

int get_key(int root, int rk) {
  if (rk <= tr[tr[root].l].sz) return get_key(tr[root].l, rk);
  else if (rk > tr[tr[root].l].sz + 1)
    return get_key(tr[root].r, rk - tr[tr[root].l].sz - 1);
  else return tr[root].key;
}

int get_prev(int &root, int v) {
  split(root, v - 1, x, y);
  if (!x) return INT_MIN;
  int res = get_key(x, tr[x].sz);
  root = merge(x, y);
  return res;
}

int get_next(int &root, int v) {
  split(root, v, x, y);
  if (!y) return INT_MAX;
  int res = get_key(y, 1);
  root = merge(x, y);
  return res;
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int vi, op, x;
    scanf("%d%d%d", &vi, &op, &x);
    root[i] = root[vi];
    if (op == 1) insert(root[i], x);
    else if (op == 2) remove(root[i], x);
    else if (op == 3) printf("%d\n", get_rank(root[i], x));
    else if (op == 4) printf("%d\n", get_key(root[i], x));
    else if (op == 5) printf("%d\n", get_prev(root[i], x));
    else printf("%d\n", get_next(root[i], x));
  }
}