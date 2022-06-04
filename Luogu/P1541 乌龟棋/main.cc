#include <iostream>
#include <cstring>
using namespace std;

const int N = 360, M = 50;
int n, m;
int a[N], b[5], f[M][M][M][M];

int dfs(int x, int b1, int b2, int b3, int b4) {
  int &v = f[b1][b2][b3][b4];
  if (~v) return v;
  if (!b1 && !b2 && !b3 && !b4) return v = a[x];
  if (b1) v = max(v, a[x] + dfs(x + 1, b1 - 1, b2, b3, b4));
  if (b2) v = max(v, a[x] + dfs(x + 2, b1, b2 - 1, b3, b4));
  if (b3) v = max(v, a[x] + dfs(x + 3, b1, b2, b3 - 1, b4));
  if (b4) v = max(v, a[x] + dfs(x + 4, b1, b2, b3, b4 - 1));
  return v;
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= m; i++) {
    int x;
    b[scanf("%d", &x), x]++;
  }
  
  memset(f, -1, sizeof f);
  printf("%d\n", dfs(1, b[1], b[2], b[3], b[4]));
}