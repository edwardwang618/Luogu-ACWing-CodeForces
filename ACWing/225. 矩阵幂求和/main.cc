#include <cstring>
#include <iostream>
using namespace std;

const int N = 65;
int n, k, MOD;
int a[N][N], res[N][N];

void mult(int a[][N], int b[][N]) {
  static int c[N][N];
  memset(c, 0, sizeof c);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      for (int k = 1; k <= n; k++)
        c[i][j] = ((c[i][j] + a[i][k] * b[k][j]) % MOD + MOD) % MOD;

  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) a[i][j] = c[i][j];
}

void fast_pow(int k) {
  while (k) {
    if (k & 1) mult(res, a);
    k >>= 1;
    mult(a, a);
  }
}

int main() {
  scanf("%d%d%d", &n, &k, &MOD);
  for (int i = 1; i <= 2 * n; i++)
    for (int j = 1; j <= 2 * n; j++) {
      if (i <= n && j <= n) scanf("%d", &a[i][j]);
      else if (j - i == n || i > n && i == j)
        a[i][j] = 1;

      if (i == j) res[i][i] = 1;
    }

  n <<= 1;
  fast_pow(k + 1);
  n >>= 1;
  for (int i = 1; i <= n; i++)
    res[i][i + n] = ((res[i][i + n] - 1) % MOD + MOD) % MOD;

  for (int i = 1; i <= n; i++) {
    for (int j = n + 1; j <= 2 * n; j++) printf("%d ", res[i][j]);
    puts("");
  }
}