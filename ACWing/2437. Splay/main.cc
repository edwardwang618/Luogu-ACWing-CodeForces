#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int n, m;
struct Node {
  int s[2], p, v;
  int sz;
  bool rev;
  void init(int _v, int _p) { v = _v, p = _p, sz = 1; }
} tr[N];
int root, idx;

#define pushup(x) tr[x].sz = tr[tr[x].s[0]].sz + tr[tr[x].s[1]].sz + 1

void pushdown(int x) {
  if (tr[x].rev) {
    swap(tr[x].s[0], tr[x].s[1]);
    tr[tr[x].s[0]].rev ^= 1;
    tr[tr[x].s[1]].rev ^= 1;
    tr[x].rev = 0;
  }
}

void rotate(int x) {
  int y = tr[x].p, z = tr[y].p, k = tr[y].s[1] == x;
  tr[z].s[tr[z].s[1] == y] = x, tr[x].p = z;
  tr[y].s[k] = tr[x].s[k ^ 1], tr[tr[x].s[k ^ 1]].p = y;
  tr[x].s[k ^ 1] = y, tr[y].p = x;
  pushup(y), pushup(x);
}

void splay(int x, int g) {
  while (tr[x].p != g) {
    int y = tr[x].p, z = tr[y].p;
    if (z != g) rotate((tr[y].s[0] == x) ^ (tr[z].s[0] == y) ? x : y);
    rotate(x);
  }

  if (!g) root = x;
}

void insert(int v) {
  int u = root, p = 0;
  while (u) p = u, u = tr[u].s[v > tr[u].v];
  u = ++idx;
  if (p) tr[p].s[v > tr[p].v] = u;
  tr[u].init(v, p);
  splay(u, 0);
}

int get_k(int k) {
  int u = root;
  while (u) {
    pushdown(u);
    if (tr[tr[u].s[0]].sz >= k)
      u = tr[u].s[0];
    else if (tr[tr[u].s[0]].sz + 1 < k)
      k -= tr[tr[u].s[0]].sz + 1, u = tr[u].s[1];
    else
      return u;
  }

  return -1;
}

void dfs(int u) {
  if (!u) return;
  pushdown(u);
  dfs(tr[u].s[0]);
  if (tr[u].v >= 1 && tr[u].v <= n) printf("%d ", tr[u].v);
  dfs(tr[u].s[1]);
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i <= n + 1; i++) insert(i);

  while (m--) {
    int l, r;
    scanf("%d%d", &l, &r);
    l = get_k(l), r = get_k(r + 2);
    splay(l, 0), splay(r, l);
    tr[tr[r].s[0]].rev ^= 1;
  }

  dfs(root);
}