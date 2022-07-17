#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

const int N = 1e4 + 10, S = 1e6 + 10;
int n, m, len, mc, mq;
int w[N], cnt[S], res[N], ans;
struct Query {
  int id, l, r, t;
} q[N];
struct Modify {
  int p, c;
} c[N];

void add(int x) {
  if (!cnt[x]) ans++;
  cnt[x]++;
}

void del(int x) {
  cnt[x]--;
  if (!cnt[x]) ans--;
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &w[i]);
  for (int i = 0; i < m; i++) {
    char op[2];
    int a, b;
    scanf("%s%d%d", op, &a, &b);
    if (*op == 'Q') mq++, q[mq] = {mq, a, b, mc};
    else c[++mc] = {a, b};
  }
  len = sqrt(n);
  sort(q + 1, q + 1 + mq, [&](Query& a, Query& b) {
    int al = a.l / len, bl = b.l / len;
    if (al != bl) return al < bl;
    int ar = a.r / len, br = b.r / len;
    if (ar != br) if (al & 1) return ar < br; else return ar > br;
    return a.t < b.t;
  });

  for (int k = 1, i = 0, j = 1, t = 0; k <= mq; k++) {
    int id = q[k].id, l = q[k].l, r = q[k].r, tm = q[k].t;
    while (i < r) add(w[++i]);
    while (i > r) del(w[i--]);
    while (j < l) del(w[j++]);
    while (j > l) add(w[--j]);

    while (t < tm) {
      t++;
      if (l <= c[t].p && c[t].p <= r) {
        del(w[c[t].p]);
        add(c[t].c);
      }
      swap(w[c[t].p], c[t].c);
    }
    while (t > tm) {
      if (l <= c[t].p && c[t].p <= r) {
        del(w[c[t].p]);
        add(c[t].c);
      }
      swap(w[c[t].p], c[t].c);
      t--;
    }

    res[id] = ans;
  }

  for (int i = 1; i <= mq; i++) printf("%d\n", res[i]);
}