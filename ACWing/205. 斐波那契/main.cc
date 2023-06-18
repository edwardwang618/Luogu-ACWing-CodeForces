#include <cstring>
#include <iostream>
using namespace std;

const int MOD = 10000;
int a[2][2];
int n;

void mult(int a[][2], int b[][2]) {
  static int c[2][2];
  memset(c, 0, sizeof c);
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++)
      for (int k = 0; k < 2; k++)
        c[i][j] = (c[i][j] + b[i][k] * a[k][j] % MOD) % MOD;
  memcpy(a, c, sizeof c);
}

int fast_pow(int n) {
  int f[2][2] = {1};
  a[0][0] = a[0][1] = a[1][0] = 1;
  a[1][1] = 0;
  while (n) {
    if (n & 1) mult(f, a);
    n >>= 1;
    mult(a, a);
  }

  return f[1][0];
}

int main() {
  while (scanf("%d", &n), ~n) printf("%d\n", fast_pow(n));
}