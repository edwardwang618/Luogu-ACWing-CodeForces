#include <iostream>
using namespace std;

const int N = 110;
int n, m;
int f[N][N];

int main() {
  scanf("%d%d", &n, &m);

  for (int i = 1; i <= n; i++) {
    int v, w, s;
    scanf("%d%d%d", &v, &w, &s);
    for (int j = 0; j <= m; j++)
      for (int k = 0; k <= s && k * v <= j; k++)
        f[i][j] = max(f[i][j], f[i - 1][j - k * v] + k * w);
  }

  printf("%d\n", f[n][m]);
}