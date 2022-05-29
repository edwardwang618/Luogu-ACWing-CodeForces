#include <iostream>
#include <cstring>
#define x first
#define y second
using namespace std;
using PII = pair<int, int>;

const int N = 110 << 1, INF = 1e9;
int n, a[N], sum[N];
int f[N][N], g[N][N];

PII dfs(int l, int r) {
  if (~f[l][r]) return {f[l][r], g[l][r]};
  if (l >= r) {
    f[l][r] = g[l][r] = 0;
    return {0, 0};
  }

  int x = INF, y = -INF;
  for (int k = l; k < r; k++) {
    auto le = dfs(l, k), ri = dfs(k + 1, r);
    int s = sum[r] - sum[l - 1];
    x = min(x, le.x + ri.x + s);
    y = max(y, le.y + ri.y + s);
  }

  f[l][r] = x, g[l][r] = y;
  return {x, y};
}

int main() {
  memset(f, -1, sizeof f);
  memset(g, -1, sizeof g);

  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    a[i + n] = a[i];
  }

  for (int i = 1; i <= n << 1; i++) sum[i] = sum[i - 1] + a[i];

  int x = INF, y = -INF;
  for (int i = 1; i <= n; i++) {
    auto p = dfs(i, i + n - 1);
    x = min(x, p.x);
    y = max(y, p.y);
  }

  printf("%d\n%d\n", x, y);
}