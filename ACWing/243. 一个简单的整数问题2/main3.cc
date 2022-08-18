#include <iostream>
#include <cmath>
using namespace std;

const int N = 100010, M = 350;
int n, m, len;
long add[M], sum[M];
int w[N];
int bel[N];

void change(int l, int r, int d) {
  if (bel[l] == bel[r]) for (int i = l; i <= r; i++) w[i] += d, sum[bel[i]] += d;
  else {
    int i = l, j = r;
    while (bel[i] == bel[l]) w[i++] += d, sum[bel[l]] += d;
    while (bel[j] == bel[r]) w[j--] += d, sum[bel[r]] += d;
    for (int k = bel[i]; k <= bel[j]; k++) sum[k] += len * d, add[k] += d;
  }
}

long query(int l, int r) {
  long res = 0;
  if (bel[l] == bel[r]) for (int i = l; i <= r; i++) res += w[i] + add[bel[i]];
  else {
    int i = l, j = r;
    while (bel[i] == bel[l]) res += w[i++] + add[bel[l]];
    while (bel[j] == bel[r]) res += w[j--] + add[bel[r]];
    for (int k = bel[i]; k <= bel[j]; k++) res += sum[k];
  }

  return res;
}

int main() {
  scanf("%d%d", &n, &m);
  len = sqrt(n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &w[i]);
    bel[i] = i / len;
    sum[bel[i]] += w[i];
  }

  char op[2];
  int l, r, d;
  while (m--) {
    scanf("%s%d%d", op, &l, &r);
    if (op[0] == 'C') {
      scanf("%d", &d);
      change(l, r, d);
    } else printf("%ld\n", query(l, r));
  }

  return 0;
}