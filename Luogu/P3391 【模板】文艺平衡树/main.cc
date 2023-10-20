#include <iostream>
using namespace std;

const int N = 1e5 + 10;
struct Node {
#define lc(p) tr[p].l
#define rc(p) tr[p].r
#define key(p) tr[p].key
#define sz(p) tr[p].sz
  int l, r;
  int key, val;
  int sz;
  bool rev;
} tr[N];
int n, m;
int root, idx;

int get_node(int key) {
  tr[++idx].key = key;
  tr[idx].val = rand();
  tr[idx].sz = 1;
  return idx;
}

#define pushup(p) sz(p) = sz(lc(p)) + sz(rc(p)) + 1

void pushdown(int p) {
  swap(lc(p), rc(p));
  tr[lc(p)].rev ^= 1;
  tr[rc(p)].rev ^= 1;
  // 懒标记下传完毕，清除当前节点懒标记
  tr[p].rev = false;
}

void split(int p, int sz, int &x, int &y) {
  if (!p)
    x = y = 0;
  else {
    // 要分裂p了，先下传懒标记
    if (tr[p].rev) pushdown(p);
    if (sz(lc(p)) < sz) {
      x = p;
      split(rc(p), sz - sz(lc(p)) - 1, rc(p), y);
    } else {
      y = p;
      split(lc(p), sz, x, lc(p));
    }

    // 分裂完之后pushup。注意，这个pushup操作必须写在else里，
    // 否则会pushup 0节点，sz会错
    pushup(p);
  }
}

// 合并，并维护大顶堆性质
int merge(int x, int y) {
  if (!x || !y) return x ^ y;
  if (tr[x].val > tr[y].val) {
    // 要将x右子树与y合并，合并之前下传x的懒标记
    if (tr[x].rev) pushdown(x);
    rc(x) = merge(rc(x), y);
    pushup(x);
    // x是新树根
    return x;
  } else {
    if (tr[y].rev) pushdown(y);
    lc(y) = merge(x, lc(y));
    pushup(y);
    return y;
  }
}

void reverse(int l, int r) {
  int x, y, z;
  split(root, l - 1, x, y);
  split(y, r - l + 1, y, z);
  tr[y].rev ^= 1;
  root = merge(merge(x, y), z);
}

// 中序遍历打印答案
void dfs(int p) {
  if (!p) return;
  if (tr[p].rev) pushdown(p);
  dfs(lc(p));
  printf("%d ", tr[p].key);
  dfs(rc(p));
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) root = merge(root, get_node(i));

  while (m--) {
    int l, r;
    scanf("%d%d", &l, &r);
    reverse(l, r);
  }

  dfs(root);
}