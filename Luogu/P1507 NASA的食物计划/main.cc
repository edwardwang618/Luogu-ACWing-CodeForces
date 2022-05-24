#include <iostream>
using namespace std;

const int N = 55;
int V, M, n;
int v[N], m[N], cal[N];
int f[410][410];

int main() {
  scanf("%d%d", &V, &M);
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    scanf("%d%d%d", &v[i], &m[i], &cal[i]);

  for (int i = 1; i <= n; i++)
    for (int j = V; j >= v[i]; j--)
      for (int k = M; k >= m[i]; k--)
        f[j][k] = max(f[j][k], f[j - v[i]][k - m[i]] + cal[i]);

  printf("%d\n", f[V][M]);
}