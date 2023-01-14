#include <iostream>
using namespace std;

const int S = 110;
int n, V, M;
int f[S][S];

int main() {
  scanf("%d%d%d", &n, &V, &M);

  for (int i = 1; i <= n; i++) {
    int v, m, w;
    scanf("%d%d%d", &v, &m, &w);
    for (int j = V; j >= 0; j--)
      for (int k = M; k >= 0; k--)
        if (j >= v && k >= m) f[j][k] = max(f[j][k], f[j - v][k - m] + w);
  }
  printf("%d\n", f[V][M]);
}