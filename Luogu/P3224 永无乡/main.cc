#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

namespace {

const int N = 1e5 + 10;
int n, m;
struct Node {
#define lc(p) tr[p].l
#define rc(p) tr[p].r
#define val(p) tr[p].val
#define id(p) tr[p].id
#define sz(p) tr[p].sz
  int l, r;
  int id, val;
  int sz, rnd;
} tr[N];
int idx;
int root[N], p[N];

int find(int x) {
  if (x == p[x]) return x;
  return p[x] = find(p[x]);
}

int get_node(int id, int val) {
  tr[++idx] = {0, 0, id, val, 1, rand()};
  return idx;
}

#define pushup(p) sz(p) = sz(lc(p)) + sz(rc(p)) + 1

int merge(int x, int y) {
  if (!x || !y) return x | y;
  if (tr[x].rnd > tr[y].rnd) {
    rc(x) = merge(rc(x), y);
    pushup(x);
    return x;
  } else {
    lc(y) = merge(x, lc(y));
    pushup(y);
    return y;
  }
}

void split(int p, int val, int &x, int &y) {
  if (!p) x = y = 0;
  else {
    if (val < val(p)) {
      y = p;
      split(lc(p), val, x, lc(p));
    } else {
      x = p;
      split(rc(p), val, rc(p), y);
    }
    pushup(p);
  }
}

int get_id(int id, int rk) {
  int p = root[id];
  while (p) {
    if (rk <= sz(lc(p))) p = lc(p);
    else if (rk > sz(lc(p)) + 1) rk -= sz(lc(p)) + 1, p = rc(p);
    else return id(p);
  }
  return -1;
}

void insert(int u, int b) {
  int x, y;
  split(root[b], val(u), x, y);
  root[b] = merge(merge(x, u), y);
}

void dfs(int u, int b) {
  if (!u) return;
  dfs(lc(u), b);
  dfs(rc(u), b);
  insert(u, b);
}

}  // namespace

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1, x; i <= n; i++) {
    scanf("%d", &x);
    p[i] = root[i] = get_node(i, x);
  }

  while (m--) {
    int x, y;
    scanf("%d%d", &x, &y);
    x = find(x), y = find(y);
    if (x != y) {
      if (sz(root[x]) > sz(root[y])) swap(x, y);
      p[x] = y;
      dfs(root[x], y);
    }
  }

  scanf("%d", &m);
  while (m--) {
    int x, y;
    char op[2];
    scanf("%s%d%d", op, &x, &y);
    x = find(x);
    if (*op == 'B') {
      y = find(y);
      if (x != y) {
        if (sz(root[x]) > sz(root[y])) swap(x, y);
        p[x] = y;
        dfs(root[x], y); 
      }
    } else {
      int rk = y;
      if (sz(root[x]) < rk) puts("-1");
      else printf("%d\n", get_id(x, rk));
    }
  }
}