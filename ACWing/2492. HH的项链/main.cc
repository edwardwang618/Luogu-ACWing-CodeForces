#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

const int N = 50010, M = 200010, S = 1000010;
int n, m, len;
int w[N], res[M], ans;
int cnt[S];
struct Query {
  int id, l, r;
} q[M];

void add(int x) {
  if (!cnt[x]) ans++;
  cnt[x]++;
}

void del(int x) {
  cnt[x]--;
  if (!cnt[x]) ans--;
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &w[i]);
  scanf("%d", &m);
  len = sqrt(double(n) * n / m) + 1;

  for (int i = 0; i < m; i++) {
    scanf("%d%d", &q[i].l, &q[i].r);
    q[i].id = i;
  }

  sort(q, q + m, [](const Query &a, const Query &b) {
    int i = a.l / len, j = b.l / len;
    if (i != j) return i < j;
    if (i & 1) return a.r < b.r;
    else return a.r > b.r;
  });

  for (int k = 0, i = 0, j = 1; k < m; k++) {
    int id = q[k].id, l = q[k].l, r = q[k].r;
    while (i < r) add(w[++i]);
    while (i > r) del(w[i--]);
    while (j < l) del(w[j++]);
    while (j > l) add(w[--j]);
    res[id] = ans;
  }

  for (int i = 0; i < m; i++) printf("%d\n", res[i]);
}