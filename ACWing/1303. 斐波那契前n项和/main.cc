#include <cstring>
#include <iostream>
using namespace std;
using ll = long long;

int n, m;
ll a[3][3], res[3][3];
void multi(ll a[][3], ll b[][3]) {
  ll c[3][3] = {0};
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      for (int k = 0; k < 3; k++) c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % m;
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++) a[i][j] = c[i][j];
}

void fast_pow(int n) {
  for (int i = 0; i < 3; i++) res[i][i] = 1;
  while (n) {
    if (n & 1) multi(res, a);
    n >>= 1;
    multi(a, a);
  }
}

int main() {
  scanf("%d%d", &n, &m);
  a[0][0] = a[0][1] = a[1][1] = a[1][2] = a[2][1] = 1;

  fast_pow(n);
  printf("%lld\n", res[0][1]);
}