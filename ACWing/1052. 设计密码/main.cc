#include <iostream>
#include <cstring>
using namespace std;

const int N = 55, mod = 1e9 + 7;
int n, m;
char s[N];
int f[N][N], ne[N];

void build_ne() {
  for (int i = 2, j = 0; i <= m; i++) {
    while (j && s[i] != s[j + 1]) j = ne[j];
    if (s[i] == s[j + 1]) j++;
    ne[i] = i < m && s[i + 1] != s[j + 1] ? j : ne[j];
  }
}

int main() {
  cin >> n >> s + 1;
  m = strlen(s + 1);
  build_ne();

  f[0][0] = 1;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      for (char ch = 'a'; ch <= 'z'; ch++) {
        int u = j;
        while (u && s[u + 1] != ch) u = ne[u];
        if (s[u + 1] == ch) u++;
        if (u < m) f[i + 1][u] = (f[i + 1][u] + f[i][j]) % mod;
      }

  int res = 0;
  for (int j = 0; j < m; j++) res = (res + f[n][j]) % mod;
  printf("%d\n", res);
}