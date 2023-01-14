#include <iostream>
using namespace std;

const int N = 200010, M = 1010;
int n, m;
int f[M];
int v[N], w[N];

int main() {
  int h1 = 0, h2 = 0, m1 = 0, m2 = 0;
  scanf("%d:%d", &h1, &m1);
  scanf("%d:%d", &h2, &m2);
  scanf("%d", &n);
  m = (h2 - h1) * 60 + m2 - m1;
  for (int i = 1; i <= n; i++) {
    int v0, w0, s;
    scanf("%d%d%d", &v0, &w0, &s);
    if (!s)
      for (int j = v0; j <= m; j++) f[j] = max(f[j], f[j - v0] + w0);
    else {
      int c = 0;
      for (int k = 1; k <= s; k <<= 1) {
        v[++c] = k * v0;
        w[c] = k * w0;
        s -= k;
      }
      if (s) v[++c] = s * v0, w[c] = s * w0;
      for (int k = 1; k <= c; k++)
        for (int j = m; j >= v[k]; j--)
          f[j] = max(f[j], f[j - v[k]] + w[k]);
    }
  }

  printf("%d\n", f[m]);
}