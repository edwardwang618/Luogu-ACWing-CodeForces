#include <iostream>
using namespace std;

const int N = 210, INF = 1e9;
int n, m;
int a[N][N], f[N][N];

int dfs(int x, int y) {
  if (f[x][y] > -INF && x != m + 1) return f[x][y];
  if (x == 1) return f[x][y] = a[x][y];

  for (int dy = -1; dy <= 1; dy++) {
    int ny = y + dy;
    if (1 <= ny && ny <= n)
      f[x][y] = max(f[x][y], a[x][y] + dfs(x - 1, ny));
  }

  return f[x][y];
}

int main() {
  scanf("%d%d", &m, &n);
  for (int i = 1; i <= m; i++)
    for (int j = 1; j <= n; j++) {
      scanf("%d", &a[i][j]);
      f[i][j] = -INF;
    }

  printf("%d\n", dfs(m + 1, n / 2 + 1));
}