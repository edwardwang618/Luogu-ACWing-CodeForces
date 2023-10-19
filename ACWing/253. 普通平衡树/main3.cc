#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int n;

struct Node {
  int l, r;
  int key, val;
  int cnt, size;
} tr[N];
int root, idx;
int x, y, z;

int get_node(int key) {
  tr[++idx].key = key;
  tr[idx].val = rand();
  tr[idx].cnt = tr[idx].size = 1;
  return idx;
}

void pushup(int p) {
  tr[p].size = tr[tr[p].l].size + tr[tr[p].r].size + tr[p].cnt;
}

int merge(int x, int y) {
  if (!x || !y) return x | y;
  if (tr[x].val > tr[y].val) {
    tr[x].r = merge(tr[x].r, y);
    pushup(x);
    return x;
  } else {
    tr[y].l = merge(x, tr[y].l);
    pushup(y);
    return y;
  }
}

void split_key(int p, int key, int &x, int &y) {
  if (!p)
    x = y = 0;
  else {
    if (tr[p].key <= key) {
      x = p;
      split_key(tr[p].r, key, tr[p].r, y);
    } else {
      y = p;
      split_key(tr[p].l, key, x, tr[p].l);
    }

    pushup(p);
  }
}

void split_size(int p, int sz, int &x, int &y) {
  if (!p)
    x = y = 0;
  else {
    if (sz > tr[tr[p].l].size) {
      x = p;
      split_size(tr[p].r, sz - tr[tr[p].l].size - tr[p].cnt, tr[p].r, y);
    } else {
      y = p;
      split_size(tr[p].l, sz, x, tr[p].l);
    }

    pushup(p);
  }
}

void insert(int key) {
  split_key(root, key, x, z);
  split_key(x, key - 1, x, y);
  if (!y)
    y = get_node(key);
  else {
    tr[y].cnt++;
    tr[y].size++;
  }

  root = merge(merge(x, y), z);
}

void remove(int key) {
  split_key(root, key, x, z);
  split_key(x, key - 1, x, y);
  if (!y)
    return;
  else if (tr[y].cnt == 1)
    y = 0;
  else if (tr[y].cnt > 1) {
    tr[y].cnt--;
    tr[y].size--;
  }

  root = merge(merge(x, y), z);
}

int get_rank_by_key(int key) {
  split_key(root, key - 1, x, y);
  key = tr[x].size + 1;
  root = merge(x, y);
  return key;
}

int get_key_by_rank(int rank) {
  split_size(root, rank, x, y);
  int p = x;
  while (tr[p].r) p = tr[p].r;
  root = merge(x, y);
  return tr[p].key;
}

int get_prev(int key) {
  split_key(root, key - 1, x, y);
  int p = x;
  while (tr[p].r) p = tr[p].r;
  root = merge(x, y);
  return tr[p].key;
}

int get_next(int key) {
  split_key(root, key, x, y);
  int p = y;
  while (tr[p].l) p = tr[p].l;
  root = merge(x, y);
  return tr[p].key;
}

int main() {
  scanf("%d", &n);
  while (n--) {
    int opt, x;
    scanf("%d%d", &opt, &x);
    if (opt == 1)
      insert(x);
    else if (opt == 2)
      remove(x);
    else if (opt == 3)
      printf("%d\n", get_rank_by_key(x));
    else if (opt == 4)
      printf("%d\n", get_key_by_rank(x));
    else if (opt == 5)
      printf("%d\n", get_prev(x));
    else if (opt == 6)
      printf("%d\n", get_next(x));
  }
}