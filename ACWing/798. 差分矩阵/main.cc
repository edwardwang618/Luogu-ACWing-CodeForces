#include <iostream>
using namespace std;

const int N = 1010;
int a[N][N], d[N][N];
int n, m, q;

int main() {
  scanf("%d%d%d", &n, &m, &q);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) scanf("%d", &a[i][j]);

  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      d[i][j] += a[i][j];
      d[i + 1][j] -= a[i][j];
      d[i][j + 1] -= a[i][j];
      d[i + 1][j + 1] += a[i][j];
    }

  while (q--) {
    int x1, y1, x2, y2, c;
    scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &c);
    d[x1][y1] += c;
    d[x1][y2 + 1] -= c;
    d[x2 + 1][y1] -= c;
    d[x2 + 1][y2 + 1] += c;
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      d[i][j] += d[i - 1][j];
      d[i][j] += d[i][j - 1];
      d[i][j] -= d[i - 1][j - 1];
      printf("%d ", d[i][j]);
    }
    puts("");
  }
}