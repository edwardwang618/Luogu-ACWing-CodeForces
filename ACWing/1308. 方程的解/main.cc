#include <iostream>
using namespace std;

const int N = 150, mod = 1000;
int k, x;
int f[1000][100][N];

int qmi(int a, int b) {
  int res = 1;
  while (b) {
    if (b & 1) res = res * a % mod;
    b >>= 1;
    a = a * a % mod;
  }
  return res;
}

void add(int a[N], int b[N], int c[N]) {
  for (int i = 0, t = 0; i < N; ++i) {
    t += b[i] + c[i];
    a[i] = t % 10;
    t /= 10;
  }
}

int main() {
  scanf("%d%d", &k, &x);
  int n = qmi(x % mod, x);

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= i && j < k; ++j) {
      if (!j)
        f[i][j][0] = 1;
      else
        add(f[i][j], f[i - 1][j], f[i - 1][j - 1]);
    }
  }

  int m = N - 1;
  while (!f[n - 1][k - 1][m]) m--;
  while (m >= 0) printf("%d", f[n - 1][k - 1][m--]);
  puts("");
}
