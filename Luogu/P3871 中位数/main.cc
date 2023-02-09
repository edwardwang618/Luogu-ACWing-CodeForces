#include <iostream>
using namespace std;

const int N = 2e5 + 10, INF = 2e9;
int n, m;
struct Node {
  int l, r;
  int key, val;
  int cnt, sz;
} tr[N];
int root, idx;

void pushup(int p) { tr[p].sz = tr[tr[p].l].sz + tr[tr[p].r].sz + tr[p].cnt; }

void zig(int &p) {
  int q = tr[p].l;
  tr[p].l = tr[q].r, tr[q].r = p, p = q;
  pushup(tr[p].r);
}

void zag(int &p) {
  int q = tr[p].r;
  tr[p].r = tr[q].l, tr[q].l = p, p = q;
  pushup(tr[p].l);
}

int get_node(int key) {
  tr[++idx].key = key;
  tr[idx].val = rand();
  tr[idx].cnt = tr[idx].sz = 1;
  return idx;
}

void insert(int &p, int key) {
  if (!p)
    p = get_node(key);
  else if (key < tr[p].key) {
    insert(tr[p].l, key);
    if (tr[tr[p].l].val > tr[p].val) zig(p);
  } else if (key > tr[p].key) {
    insert(tr[p].r, key);
    if (tr[tr[p].r].val > tr[p].val) zag(p);
  } else
    tr[p].cnt++;

  pushup(p);
}

int get_key_by_rank(int p, int rank) {
  if (!p) return INF;
  if (rank <= tr[tr[p].l].sz)
    return get_key_by_rank(tr[p].l, rank);
  else if (rank > tr[tr[p].l].sz + tr[p].cnt)
    return get_key_by_rank(tr[p].r, rank - tr[tr[p].l].sz - tr[p].cnt);
  else
    return tr[p].key;
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int x;
    scanf("%d", &x);
    insert(root, x);
  }

  scanf("%d", &m);
  while (m--) {
    string op;
    int x;
    cin >> op;
    if (op == "add") {
      scanf("%d", &x);
      insert(root, x);
      n++;
    } else
      printf("%d\n", get_key_by_rank(root, (n + 1) / 2));
  }
}