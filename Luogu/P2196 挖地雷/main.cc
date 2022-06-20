#include <iostream>
using namespace std;

const int N = 205;
int n, a[N], f[N], path[N], cnt;
bool g[N][N];
int res, pre[N], ed;

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++)
      scanf("%d", &g[i][j]);

  for (int i = 1; i <= n; i++) { 
    f[i] = a[i];
    for (int j = 1; j < i; j++)
      if (g[j][i] && f[i] < f[j] + a[i])
        f[i] = f[j] + a[i], pre[i] = j;
    if (f[i] > res) res = f[i], ed = i;
  }

  while (ed) path[++cnt] = ed, ed = pre[ed];
  for (int i = cnt; i; i--) printf("%d ", path[i]);
  puts("");
  printf("%d\n", res);
}