#include <iostream>
#include <cstring>
using namespace std;

const int N = 110, K = 110;
int n, k;
int a[N];
int f[N][K];

int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  memset(f, -1, sizeof f);
  f[0][0] = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 0; j < k; j++) {
      f[i][j] = f[i - 1][j];
      int x = ((j - a[i]) % k + k) % k;
      if (~f[i - 1][x]) f[i][j] = max(f[i][j], f[i - 1][x] + a[i]);
    }
  printf("%d\n", ~f[n][0] ? f[n][0] : 0);
}