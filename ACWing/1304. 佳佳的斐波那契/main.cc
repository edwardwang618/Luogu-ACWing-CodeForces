#include <iostream>
using namespace std;

using ll = long long;

int n, m;
ll a[4][4], res[4][4];
void mult(ll a[][4], ll b[][4]) {
  ll c[4][4] = {0};
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 4; j++)
      for (int k = 0; k < 4; k++) c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % m;
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 4; j++) a[i][j] = c[i][j];
}

void fast_pow(int n) {
  while (n) {
    if (n & 1) mult(res, a);
    n >>= 1;
    mult(a, a);
  }
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < 4; i++) res[i][i] = 1;
  a[0][0] = a[0][1] = a[1][1] = a[1][2] = a[2][2] = a[2][3] = a[3][2] = 1;
  fast_pow(n);
  ll pn = res[0][2], sn = res[1][2];
  printf("%lld\n", ((n * sn - pn) % m + m) % m);
}