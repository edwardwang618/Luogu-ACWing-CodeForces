#include <iostream>
using namespace std;

const int N = 5010, MOD = 10000;
int f[N][N];
int n, k;

int main() {
  scanf("%d%d", &n, &k);
  f[0][0] = 1;
  for (int i = 1; i <= n; i++)
    for (int j = 0; j <= k; j++)
      for (int l = 0; l <= min(j, i - 1); l++)
        f[i][j] = (f[i][j] + f[i - 1][j - l]) % MOD;

  printf("%d\n", f[n][k]);
}