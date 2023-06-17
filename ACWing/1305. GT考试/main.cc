#include <iostream>
#include <cstring>
using namespace std;

const int N = 1e9 + 10, M = 30;
int n, m, P;
char s[M];
int ne[M], c[M][M], f[M][M];

void mult(int a[][M], int b[][M]) {
  static int res[M][M];
  memset(res, 0, sizeof res);
  for (int i = 0; i < m; i++)
    for (int j = 0; j < m; j++)
      for (int k = 0; k < m; k++)
        res[i][j] = (res[i][j] + b[i][k] * a[k][j]) % P;
  for (int i = 0; i < m; i++)
    for (int j = 0; j < m; j++) a[i][j] = res[i][j];
}

void fast_pow(int n) {
  f[0][0] = 1;
  while (n) {
    if (n & 1) mult(f, c);
    n >>= 1;
    mult(c, c);
  }
}

int main() {
  scanf("%d%d%d", &n, &m, &P);
  scanf("%s", s + 1);
  for (int i = 2, j = 0; i <= m; i++) {
    while (j && s[i] != s[j + 1]) j = ne[j];
    if (s[i] == s[j + 1]) j++;
    ne[i] = j;
  }

  for (int j = 0; j < m; j++)
    for (char ch = '0'; ch <= '9'; ch++) {
      int k = j;
      while (k && s[k + 1] != ch) k = ne[k];
      if (s[k + 1] == ch) k++;
      if (k < m) c[k][j]++;
    }

  fast_pow(n);
  int res = 0;
  for (int i = 0; i < m; i++) res = (res + f[i][0]) % P;
  printf("%d\n", res);
}