#include <iostream>
using namespace std;

namespace {
const int N = 4e5 + 10;
int n, m;
struct Node {
#define lc(p) tr[p].l
#define rc(p) tr[p].r
#define key(p) tr[p].key
#define sz(p) tr[p].sz
  int l, r;
  int key, val;
  int sz;
} tr[N];
int idx, root;
int delta;
int x, y, z;
int res;

#define pushup(p) sz(p) = sz(lc(p)) + sz(rc(p)) + 1

int get_node(int k) {
  tr[++idx] = {0, 0, k, rand(), 1};
  return idx;
}

int merge(int x, int y) {
  if (!x || !y) return x | y;
  if (tr[x].val > tr[y].val) {
    rc(x) = merge(rc(x), y);
    pushup(x);
    return x;
  } else {
    lc(y) = merge(x, lc(y));
    pushup(y);
    return y;
  }
}

void split(int p, int k, int &x, int &y) {
  if (!p) x = y = 0;
  else {
    if (k >= key(p)) x = p, split(rc(p), k, rc(p), y);
    else y = p, split(lc(p), k, x, lc(p));
    pushup(p);
  }
}

void insert(int k) {
  split(root, k, x, z);
  y = get_node(k);
  root = merge(merge(x, y), z);
}

void minus_k() {
  split(root, m - delta - 1, x, y);
  res += sz(x);
  root = y;
}

int get_k(int k) {
  int u = root;
  while (u) {
    if (k <= sz(lc(u))) u = lc(u);
    else if (sz(lc(u)) + 1 < k)
      k -= sz(lc(u)) + 1, u = rc(u);
    else return key(u);
  }

  return -1;
}
}  // namespace

int main() {
  scanf("%d%d", &n, &m);
  while (n--) {
    char op[2];
    int k;
    scanf("%s%d\n", op, &k);
    if (op[0] == 'I') {
      if (k < m) continue;
      insert(k - delta);
    } else if (op[0] == 'A') delta += k;
    else if (op[0] == 'S') {
      delta -= k;
      minus_k();
    } else {
      if (k > sz(root)) puts("-1");
      else
        printf("%d\n", get_k(sz(root) - k + 1) + delta);
    }
  }

  printf("%d\n", res);
}