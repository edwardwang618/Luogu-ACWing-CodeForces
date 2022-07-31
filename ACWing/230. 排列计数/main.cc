#include <iostream>
#include <cstring>
using namespace std;

const int N = 1e6 + 10, P = 1e9 + 7;
long fac[N], f[N], inv[N];
int n, m;

long fast_pow(long x, int p) {
  long res = 1;
  while (p) {
    if (p & 1) res = res * x % P;
    x = x * x % P;
    p >>= 1;
  }
  return res;
}

long inverse(int i) {
  if (~inv[i]) return inv[i];
  return inv[i] = fast_pow(fac[i], P - 2);
}

long comb(int n, int m) {
  return fac[n] * inverse(m) % P * inverse(n - m) % P;
}

int main() {
  memset(inv, -1, sizeof inv);
  f[0] = 1, f[1] = 0;
  fac[0] = fac[1] = 1;
  for (int i = 2; i < N; i++) {
    f[i] = (i - 1) * (f[i - 1] + f[i - 2]) % P;
    fac[i] = fac[i - 1] * i % P;
  }

  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &n, &m);
    printf("%ld\n", comb(n, m) * f[n - m] % P);
  }
}