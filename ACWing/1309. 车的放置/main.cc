#include <iostream>
using namespace std;
using ll = long long;

const int N = 2010, MOD = 100003;
int a, b, c, d, k;
ll C[N][N], A[N][N];

int main() {
  scanf("%d%d%d%d%d", &a, &b, &c, &d, &k);
  for (int i = 0; i <= max(max(b, d), a + c); i++)
    for (int j = 0, fact = 1; j <= i; j++) {
      if (!j) C[i][j] = 1;
      else {
        C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
        fact = fact * j % MOD;
      }
      A[i][j] = C[i][j] * fact % MOD;
    }

  int res = 0;
  for (int x = 0; x <= b; x++)
    res = (res + C[b][x] * A[a][x] % MOD * C[d][k - x] % MOD *
                     A[a + c - x][k - x] % MOD) % MOD;
  printf("%d\n", res);
}