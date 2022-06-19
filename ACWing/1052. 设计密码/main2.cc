#include <iostream>
#include <cstring>
using namespace std;

const int N = 55, mod = 1e9 + 7;
int n, m;
char s[N];
int f[N][N];
int ne[N];

void build_ne() {
  ne[0] = -1;
  for (int i = 0, j = -1; i < m - 1;)
    if (j < 0 || s[j] == s[i]) {
      i++;
      j++;
      ne[i] = s[i] != s[j] ? j : ne[j];
    } else j = ne[j];
}

int main() {
  scanf("%d%s", &n, s);
  m = strlen(s);
  build_ne();

  f[0][0] = 1;
  for (int i = 1; i <= n; i++)
    for (int j = 0; j < m; j++)
      for (char ch = 'a'; ch <= 'z'; ch++) {
        int u = j;
        while (u != -1 && ch != s[u]) u = ne[u];
        u++;
        if (u < m) f[i][u] = (f[i][u] + f[i - 1][j]) % mod;
      }

  int res = 0;
  for (int i = 0; i < m; i++) res = (res + f[n][i]) % mod;
  printf("%d\n", res);
}
