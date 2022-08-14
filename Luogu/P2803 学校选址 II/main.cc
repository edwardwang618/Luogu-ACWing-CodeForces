#include <iostream>
#include <cstring>
using namespace std;

const int N = 110;
int n, K;
int dis[N];
int g[N][N], f[N][N], w[N];

int main() {
  scanf("%d%d", &n, &K);
  for (int i = 1; i <= n; i++) {
    int x;
    scanf("%d", &x);
    w[i] = w[i - 1] + x;
  }
  for (int i = 2; i <= n; i++) {
    int x;
    scanf("%d", &x);
    dis[i] = dis[i - 1] + x;
  }

  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= i; j++) {
      int k;
      for (k = j; k <= i; k++)
        if (w[k] - w[j - 1] >= w[i] - w[k]) break;
      k = min(k, i);

      for (int l = j; l <= i; l++)
        g[j][i] += abs(dis[k] - dis[l]) * (w[l] - w[l - 1]);
    }

  memset(f, 0x3f, sizeof f);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= K; j++) {
      if (j >= i) f[i][j] = 0;
      else if (j == 1) f[i][j] = g[1][i];
      else {
        for (int l = 1; l <= i; l++)
          f[i][j] = min(f[i][j], f[l - 1][j - 1] + g[l][i]);
      }
    }

  printf("%d\n", f[n][K]);
}