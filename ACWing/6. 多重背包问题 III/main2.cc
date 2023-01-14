#include <iostream>
using namespace std;

const int N = 1010, M = 20010;
int n, m;
int f[2][M];
int q[M];

int main() {
  scanf("%d%d", &n, &m);

  for (int i = 1; i <= n; i++) {
    // v体积，w价值，s个数
    int v, w, s;
    scanf("%d%d%d", &v, &w, &s);

    for (int j = 0; j < v; j++) {
      int hh = 0, tt = 0;
      for (int k = j; k <= m; k += v) {
        if (hh < tt && q[hh] < k - s * v) hh++;
        while (hh < tt && f[i - 1 & 1][q[tt - 1]] - q[tt - 1] / v * w <=
                              f[i - 1 & 1][k] - k / v * w)
          tt--;

        q[tt++] = k;
        f[i & 1][k] = f[i - 1 & 1][q[hh]] + (k - q[hh]) / v * w;
      }
    }
  }
  printf("%d\n", f[n & 1][m]);
}