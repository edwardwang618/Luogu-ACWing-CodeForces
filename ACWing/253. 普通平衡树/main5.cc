#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100010, INF = 1e9;
int root, idx;
struct Node {
  int ch[2], key, val, cnt, sz;
} tr[N];

#define lc(x) tr[x].ch[0]
#define rc(x) tr[x].ch[1]

int get_node(int key) {
  tr[++idx] = {{0, 0}, key, rand(), 1, 1};
  return idx;
}

#define pushup(p) tr[p].sz = tr[lc(p)].sz + tr[rc(p)].sz + tr[p].cnt

void rotate(int &p, int d) {
  int q = tr[p].ch[d ^ 1];
  tr[p].ch[d ^ 1] = tr[q].ch[d], tr[q].ch[d] = p, p = q;
  pushup(tr[p].ch[d]), pushup(p);
}

void insert(int &p, int key) {
  if (!p) p = get_node(key);
  else if (tr[p].key == key) tr[p].cnt++;
  else {
    int d = tr[p].key < key;
    insert(tr[p].ch[d], key);
    if (tr[tr[p].ch[d]].val > tr[p].val) rotate(p, d ^ 1);
  }
  pushup(p);
}

void remove(int &p, int key) {
  if (!p) return;
  if (tr[p].key == key) {
    if (tr[p].cnt > 1) tr[p].cnt--;
    else if (lc(p) && rc(p)) {
      int d = tr[lc(p)].val > tr[rc(p)].val;
      rotate(p, d);
      remove(tr[p].ch[d], key);
    } else p = lc(p) ?: rc(p);
  } else remove(tr[p].ch[tr[p].key < key], key);
  pushup(p);
}

int get_rank_by_key(int p, int key) {
  if (!p) return 0;
  if (tr[p].key > key) return get_rank_by_key(lc(p), key);
  else if (tr[p].key < key)
    return tr[lc(p)].sz + tr[p].cnt + get_rank_by_key(rc(p), key);
  return tr[lc(p)].sz + 1;
}

int get_key_by_rank(int p, int rank) {
  if (!p) return INF;
  if (tr[lc(p)].sz >= rank) return get_key_by_rank(lc(p), rank);
  if (tr[lc(p)].sz + tr[p].cnt < rank)
    return get_key_by_rank(rc(p), rank - tr[lc(p)].sz - tr[p].cnt);
  return tr[p].key;
}

int get_prev(int p, int key) {
  if (!p) return -INF;
  if (tr[p].key >= key) return get_prev(lc(p), key);
  return max(tr[p].key, get_prev(rc(p), key));
}

int get_next(int p, int key) {
  if (!p) return INF;
  if (tr[p].key <= key) return get_next(rc(p), key);
  return min(tr[p].key, get_next(lc(p), key));
}

int main() {
  int n;
  scanf("%d", &n);
  while (n--) {
    int opt, x;
    scanf("%d%d", &opt, &x);
    if (opt == 1) insert(root, x);
    else if (opt == 2) remove(root, x);
    else if (opt == 3) printf("%d\n", get_rank_by_key(root, x));
    else if (opt == 4) printf("%d\n", get_key_by_rank(root, x));
    else if (opt == 5) printf("%d\n", get_prev(root, x));
    else printf("%d\n", get_next(root, x));
  }
}
