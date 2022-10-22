#include <iostream>
#include <cmath>
using namespace std;

const int N = 1e5 + 10, M = 1000;
int n, m;
int w[N], bel[N];
int len;
int sum[M], tag[M];

void modify(int l, int r) {
  int bl = bel[l], br = bel[r];
  if (bl == br)
    for (int i = l; i <= r; i++) w[i] ^= 1, sum[bl] += (w[i] ^ tag[bl]) * 2 - 1;
  else {
    int i = l, j = r;
    while (bel[i] == bl) w[i] ^= 1, sum[bl] += (w[i++] ^ tag[bl]) * 2 - 1;
    while (bel[j] == br) w[j] ^= 1, sum[br] += (w[j--] ^ tag[br]) * 2 - 1;
    for (int k = bel[i]; k <= bel[j]; k++) {
      tag[k] ^= 1;
      sum[k] = len - sum[k];
    }
  }
}

int query(int l, int r) {
  int res = 0, bl = bel[l], br = bel[r];
  if (bl == br) for (int i = l; i <= r; i++) res += w[i] ^ tag[bl];
  else {
    int i = l, j = r;
    while (bel[i] == bl) res += w[i++] ^ tag[bl];
    while (bel[j] == br) res += w[j--] ^ tag[br];
    for (int k = bel[i]; k <= bel[j]; k++) res += sum[k];
  }
  return res;
}

int main() {
  scanf("%d%d", &n, &m);
  len = sqrt(n);
  for (int i = 1; i <= n; i++) bel[i] = i / len;

  while (m--) {
    int op, l, r;
    scanf("%d%d%d", &op, &l, &r);
    if (!op) modify(l, r);
    else printf("%d\n", query(l, r));
  }
}