#include <iostream>

using namespace std;
using PII = pair<int, int>;

const int N = 1010;
int n;
int a[N][N];
int f[N][N][2];
char d[N][N][2], path[N * N];
bool zero;
int xid;

PII calc(int x) {
  PII p = {0, 0};
  if (!x) return p;
  int y = x;
  while (y % 2 == 0) {
    p.first++;
    y /= 2;
  }
  y = x;
  while (y % 5 == 0) {
    p.second++;
    y /= 5;
  }
  return p;
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      scanf("%d", &a[i][j]);

  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      if (!a[i][j]) {
        zero = true;
        xid = i;
      }

      PII p = calc(a[i][j]);
      f[i][j][0] = p.first, f[i][j][1] = p.second;
      for (int k = 0; k <= 1; k++) {
        if (i > 1 && j > 1) {
          if (f[i - 1][j][k] <= f[i][j - 1][k]) {
            f[i][j][k] += f[i - 1][j][k];
            d[i][j][k] = 'D';
          } else {
            f[i][j][k] += f[i][j - 1][k];
            d[i][j][k] = 'R';
          }
        } else if (i > 1) {
          f[i][j][k] += f[i - 1][j][k];
          d[i][j][k] = 'D';
        } else if (j > 1) {
          f[i][j][k] += f[i][j - 1][k];
          d[i][j][k] = 'R';
        }
      }
    }

  int res, k;
  if (f[n][n][0] <= f[n][n][1]) k = 0;
  else k = 1;
  res = f[n][n][k];
  printf("%d\n", zero ? min(1, res) : res);

  if (zero && res) {
    for (int i = 1; i < xid; i++) putchar('D');
    for (int i = 1; i < n; i++) putchar('R');
    for (int i = xid; i < n; i++) putchar('D');
  } else {
    int idx = 0;
    int x = n, y = n;
    while (x > 1 || y > 1) {
      path[++idx] = d[x][y][k];
      if (d[x][y][k] == 'D') x--;
      else y--;
    }
    for (int i = idx; i; i--) putchar(path[i]);
  }
}