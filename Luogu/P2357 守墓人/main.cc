#include <iostream>
#include <cmath>

using namespace std;
const int N = 2e5 + 10, M = 600;
int n, m, len;
long add[M], sum[M];
long a[N];
int bel[N];

void modify(int l, int r, long k) {
  if (bel[l] == bel[r]) for (int i = l; i <= r; i++) a[i] += k, sum[bel[l]] += k;
  else {
    int i = l, j = r;
    while (bel[i] == bel[l]) sum[bel[l]] += k, a[i++] += k;
    while (bel[j] == bel[r]) sum[bel[r]] += k, a[j--] += k;
    for (int b = bel[i]; b <= bel[j]; b++) sum[b] += k * len, add[b] += k;
  }
}

long query(int l, int r) {
  long res = 0;
  if (bel[l] == bel[r]) for (int i = l; i <= r; i++) res += a[i] + add[bel[l]];
  else {
    int i = l, j = r;
    while (bel[i] == bel[l]) res += a[i++] + add[bel[l]];
    while (bel[j] == bel[r]) res += a[j--] + add[bel[r]];
    for (int b = bel[i]; b <= bel[j]; b++) res += sum[b];
  }
  return res;
}

int main() {
  scanf("%d%d", &n, &m);
  len = sqrt(n);
  for (int i = 1; i <= n; i++) {
    scanf("%ld", &a[i]);
    bel[i] = i / len;
    sum[bel[i]] += a[i];
  }

  while (m--) {
    int op, l, r;
    long k;
    scanf("%d", &op);
    if (op == 1) {
      scanf("%d%d%ld", &l, &r, &k);
      modify(l, r, k);
    } else if (op == 2 || op == 3) {
      scanf("%ld", &k);
      if (op == 3) k = -k;
      modify(1, 1, k);
    } else if (op == 4) {
      scanf("%d%d", &l, &r);
      printf("%ld\n", query(l, r));
    } else printf("%ld\n", query(1, 1));
  }
}