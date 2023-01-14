#include <iostream>
using namespace std;

const int N = 15000;
int n, m;
int v[N], w[N], cnt;
int f[N];

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    int a, b, s;
    scanf("%d%d%d", &a, &b, &s);
    for (int k = 1; k <= s; k <<= 1) {
      v[++cnt] = a * k;
      w[cnt] = b * k;
      s -= k;
    }

    if (s) {
      v[++cnt] = a * s;
      w[cnt] = b * s;
    }
  }

  n = cnt;
  for (int i = 1; i <= n; i++)
    for (int j = m; j >= v[i]; j--) 
      f[j] = max(f[j], f[j - v[i]] + w[i]);

  printf("%d\n", f[m]);
}