#include <cmath>
#include <cstring>
#include <iostream>
using namespace std;

const int N = 2e5 + 10, M = 19;
int n, m;
int f[N][M];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &f[i][0]);

  for (int j = 1; 1 << j < n; j++)
    for (int i = 1; i + (1 << j) - 1 <= n; i++)
      f[i][j] = max(f[i][j - 1], f[i + (1 << j - 1)][j - 1]);

  scanf("%d", &m);
  while (m--) {
    int l, r;
    scanf("%d%d", &l, &r);
    int k = log2(r - l + 1);
    printf("%d\n", max(f[l][k], f[r - (1 << k) + 1][k]));
  }
}