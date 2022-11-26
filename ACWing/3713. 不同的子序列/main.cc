#include <iostream>
#include <cstring>
using namespace std;

const int N = 1e4 + 10, mod = 1e9 + 7;
int Q;
char s[N], t[N];
int f[2][N];

int main() {
  scanf("%d\n", &Q);
  while (Q--) {
    scanf("%s", s + 1);
    scanf("%s", t + 1);
    int n = strlen(s + 1), m = strlen(t + 1);
    if (n < m) {
      puts("0");
      continue;
    }

    memset(f, 0, sizeof f);
    for (int j = 0; j <= n; j++) f[0][j] = 1;
    int i;
    for (i = 1; i <= m; i++) {
      for (int j = 0; j <= n; j++) {
        f[i & 1][j] = f[i & 1][j - 1];
        if (s[j] == t[i])
          f[i & 1][j] = (f[i & 1][j] + f[i - 1 & 1][j - 1]) % mod;
      }

      if (!f[i & 1][n]) break;
    }

    if (i <= m)
      puts("0");
    else
      printf("%d\n", f[m & 1][n]);
  }
}