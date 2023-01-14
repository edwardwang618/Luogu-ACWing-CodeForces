#include <iostream>
using namespace std;

const int N = 110, M = 4e4 + 10;
int n, m;
int v[N], w[N], s[N];
int f[N][M];
int q[M];

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d%d%d", &w[i], &v[i], &s[i]);

  for (int i = 1; i <= n; i++)
    for (int j = 0; j < v[i]; j++) {
      int hh = 0, tt = 0;
      for (int k = 0; k <= (m - j) / v[i]; k++) {
        int l = j + k * v[i];
        if (hh < tt && v[i] * s[i] < l - q[hh]) hh++;
        while (hh < tt && f[i - 1][q[tt - 1]] - q[tt - 1] / v[i] * w[i] <=
                              f[i - 1][l] - k * w[i])
          tt--;
        q[tt++] = l;
        f[i][l] = f[i - 1][q[hh]] + (l - q[hh]) / v[i] * w[i];
      }
    }

  printf("%d\n", f[n][m]);
}