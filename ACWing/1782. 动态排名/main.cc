#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e5 + 10;
int n, m, maxn, n1, n2;
int a[N], b[N << 1];
struct Query {
  char op;
  int l, r, k;
  int pos, x;
} q[N];

struct Node {
#define cnt(u) tr[u].cnt
#define l(u) tr[u].l
#define r(u) tr[u].r
#define lc(u) tr[u].lc
#define rc(u) tr[u].rc
  int l, r;
  int lc, rc;
  int cnt;
} tr[N * 300];
int idx, root[N];
int t1[N], t2[N];

#define lowbit(x) (x) & (-x)

void insert(int &rt, int l, int r, int x, int c) {
  if (!rt) rt = ++idx;
  tr[rt].cnt += c;
  tr[rt].l = l;
  tr[rt].r = r;
  if (l == r) return;
  int m = (l + r) >> 1;
  if (x <= m)
    insert(lc(rt), l, m, x, c);
  else
    insert(rc(rt), m + 1, r, x, c);
}

void add(int i, int val) {
  int x = lower_bound(b + 1, b + 1 + maxn, a[i]) - b;
  for (; i <= n; i += lowbit(i)) insert(root[i], 1, maxn, x, val);
}

int dfs(int l, int r, int k) {
  if (l == r) return l;
  int m = l + r >> 1, cnt = 0;
  for (int i = 1; i <= n2; ++i) cnt += cnt(lc(t2[i]));
  for (int i = 1; i <= n1; ++i) cnt -= cnt(lc(t1[i]));
  if (cnt >= k) {
    for (int i = 1; i <= n1; ++i) t1[i] = lc(t1[i]);
    for (int i = 1; i <= n2; ++i) t2[i] = lc(t2[i]);
    return dfs(l, m, k);
  } else {
    for (int i = 1; i <= n1; ++i) t1[i] = rc(t1[i]);
    for (int i = 1; i <= n2; ++i) t2[i] = rc(t2[i]);
    return dfs(m + 1, r, k - cnt);
  }
}

int get_val_from_rank(int l, int r, int k) {
  n1 = n2 = 0;
  for (int i = l - 1; i; i -= lowbit(i)) t1[++n1] = root[i];
  for (int i = r; i; i -= lowbit(i)) t2[++n2] = root[i];
  return dfs(1, maxn, k);
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    b[++maxn] = a[i];
  }
  for (int i = 1; i <= m; ++i) {
    char op[2];
    scanf("%s", op);
    if (*op == 'Q') {
      q[i].op = 'Q';
      scanf("%d%d%d", &q[i].l, &q[i].r, &q[i].k);
    } else {
      q[i].op = 'C';
      scanf("%d%d", &q[i].pos, &q[i].x);
      b[++maxn] = q[i].x;
    }
  }
  sort(b + 1, b + 1 + maxn);
  maxn = unique(b + 1, b + 1 + maxn) - b - 1;
  for (int i = 1; i <= n; ++i) add(i, 1);
  for (int i = 1; i <= m; ++i) {
    if (q[i].op == 'Q')
      printf("%d\n", b[get_val_from_rank(q[i].l, q[i].r, q[i].k)]);
    else {
      add(q[i].pos, -1);
      a[q[i].pos] = q[i].x;
      add(q[i].pos, 1);
    }
  }
}