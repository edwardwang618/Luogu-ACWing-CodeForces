#include <iostream>
using namespace std;

const int N = 100010, MOD = 1e9 + 9;
int n;
long f[N], s[N];
long fact[N], inv[N];

long fast_pow(long x, int k) {
  long res = 1;
  while (k) {
    if (k & 1) res = res * x % MOD;
    x = x * x % MOD;
    k >>= 1;
  }

  return res;
}

void init() {
  fact[0] = inv[0] = 1;
  for (int i = 1; i <= n; i++) {
    fact[i] = fact[i - 1] * i % MOD;
    inv[i] = fast_pow(fact[i], MOD - 2);
  }
}

long C(int a, int b) {
  return fact[a] * inv[b] % MOD * inv[a - b] % MOD;
}

int main() {
  scanf("%d", &n);
  init();
  for (int i = n; i; i--) {
    s[i] = 1;
    if (i * 2 <= n) s[i] += s[i * 2];
    if (i * 2 + 1 <= n) s[i] += s[i * 2 + 1];
  }

  for (int i = n; i; i--) {
    f[i] = 1;
    if (i * 2 <= n) f[i] = f[i * 2];
    if (i * 2 + 1 <= n) f[i] = f[i] * C(s[i] - 1, s[i * 2]) % MOD * f[i * 2 + 1] % MOD;
  }
  printf("%ld\n", f[1]);
}