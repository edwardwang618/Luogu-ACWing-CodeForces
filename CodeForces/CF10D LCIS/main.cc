#include <iostream>
using namespace std;

const int N = 510;
int n, m;
int a[N], b[N];
int f[N][N], pre[N][N];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  scanf("%d", &m);
  for (int i = 1; i <= m; i++) scanf("%d", &b[i]);

  for (int i = 1; i <= n; i++)
    for (int j = 1, p = 0; j <= m; j++) {
      f[i][j] = f[i - 1][j];
      pre[i][j] = pre[i - 1][j];
      if (a[i] == b[j] && f[i - 1][p] + 1 > f[i][j]) {
        f[i][j] = f[i - 1][p] + 1;
        pre[i][j] = p;
      }
      if (b[j] < a[i] && f[i - 1][j] > f[i - 1][p])
        p = j;
    }

  int res = 0, p;
  for (int i = 1; i <= m; i++)
    if (res < f[n][i]) {
      res = f[n][i];
      p = i;
    }

  printf("%d\n", res);

  m = res;
  while (p) {
    a[m--] = b[p];
    p = pre[n][p];
  }

  for (int i = 1; i <= res; i++) printf("%d ", a[i]);
}