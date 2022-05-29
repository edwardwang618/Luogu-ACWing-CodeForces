#include <iostream>
using namespace std;

const int N = 360, M = 45;
int n, m;
int a[N], b[5];
int f[M][M][M][M];

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= m; i++) {
    int x;
    scanf("%d", &x);
    b[x]++;
  }

  f[0][0][0][0] = a[1];
  for (int x1 = 0; x1 <= b[1]; x1++)
    for (int x2 = 0; x2 <= b[2]; x2++)
      for (int x3 = 0; x3 <= b[3]; x3++)
        for (int x4 = 0; x4 <= b[4]; x4++) {
          int &v = f[x1][x2][x3][x4];
          int s = a[1 + x1 + 2 * x2 + 3 * x3 + 4 * x4];
          if (x1) v = max(v, f[x1 - 1][x2][x3][x4] + s);
          if (x2) v = max(v, f[x1][x2 - 1][x3][x4] + s);
          if (x3) v = max(v, f[x1][x2][x3 - 1][x4] + s);
          if (x4) v = max(v, f[x1][x2][x3][x4 - 1] + s);
        }

  printf("%d\n", f[b[1]][b[2]][b[3]][b[4]]);
}