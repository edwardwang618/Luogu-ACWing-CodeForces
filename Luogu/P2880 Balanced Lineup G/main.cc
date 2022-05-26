#include <iostream>
#include <cmath>
using namespace std;

const int N = 5e4 + 10;
int n, q;
int f[N][30], g[N][30];

void init() {
  for (int i = 1; i <= n; i++) g[i][0] = f[i][0];
  for (int k = 1; k <= log2(n); k++)
    for (int l = 1; l + (1 << k) - 1 <= n; l++) {
      f[l][k] = max(f[l][k - 1], f[l + (1 << k - 1)][k - 1]);
      g[l][k] = min(g[l][k - 1], g[l + (1 << k - 1)][k - 1]);
    }
}

int query(int l, int r) {
  int k = log2(r - l + 1);
  return max(f[l][k], f[r - (1 << k) + 1][k]) - min(g[l][k], g[r - (1 << k) + 1][k]);
}

int main() {
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; i++) scanf("%d", &f[i][0]);

  init();

  while (q--) {
    int l, r;
    scanf("%d%d", &l, &r);
    printf("%d\n", query(l, r));
  }
}