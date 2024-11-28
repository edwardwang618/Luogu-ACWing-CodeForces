#include <iostream>
using namespace std;

const int N = 1010;
int m, n, q;
int a[N][N];
int d[N][N];

int main() {
  scanf("%d%d%d", &m, &n, &q);
  for (int i = 1; i <= m; i++)
    for (int j = 1; j <= n; j++) {
      scanf("%d", &a[i][j]);
      d[i][j] = a[i][j] - a[i - 1][j] - a[i][j - 1] + a[i - 1][j - 1];
    }

  while (q--) {
    int x1, y1, x2, y2, c;
    scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &c);
    d[x1][y1] += c;
    d[x1][y2 + 1] -= c;
    d[x2 + 1][y1] -= c;
    d[x2 + 1][y2 + 1] += c;
  }

  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      a[i][j] = d[i][j] + a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
      printf("%d ", a[i][j]);
    }
    puts("");
  }
}