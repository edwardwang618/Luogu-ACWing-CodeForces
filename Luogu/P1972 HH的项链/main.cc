#include <iostream>
#include <algorithm>
#define lowbit(x) (x & -x)
using namespace std;

const int N = 1e6 + 10;
int n, m, a[N], res[N], f[N];
struct Query {
  int id, l, r;
} q[N];
int tr[N];

inline void add(int k, int x) {
  for (; k <= n; k += lowbit(k)) tr[k] += x;
}

inline int sum(int k) {
  int res = 0;
  for (; k; k -= lowbit(k)) res += tr[k];
  return res;
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    scanf("%d%d", &q[i].l, &q[i].r);
    q[i].id = i;
  }

  sort(q, q + m, [&](Query &q1, Query &q2) {
    return q1.r < q2.r;
  });

  for (int i = 1, k = 0; k < m; k++) {
    int r = q[k].r, l = q[k].l, id = q[k].id;
    for (; i <= n && i <= r; i++) {
      if (f[a[i]]) add(f[a[i]], -1);
      f[a[i]] = i;
      add(i, 1);
    }
    res[id] = sum(r) - sum(l - 1);
  }

  for (int i = 0; i < m; i++) printf("%d\n", res[i]);
}