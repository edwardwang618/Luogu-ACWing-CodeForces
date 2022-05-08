#include <iostream>
using namespace std;

const int N = 510, M = 1024 << 1;
int n, m;
int g[N][N], d[N];
int res[(M >> 1) + 10], cnt;

void dfs(int u) {
  for (int i = 1; i <= n; i++)
    if (g[u][i]) {
      g[u][i]--;
      g[i][u]--;
      dfs(i);
    }

  res[cnt++] = u;
}

int main() {
  scanf("%d", &m);
  while (m--) {
    int a, b;
    scanf("%d%d", &a, &b);
    g[a][b]++;
    g[b][a]++;
    d[b]++;
    d[a]++;
    n = max(n, max(a, b));
  }

  int S = 1;
  for (int i = 1; i <= n; i++)
    if (d[i] & 1) {
      S = i;
      break;
    }

  dfs(S);
  for (int i = cnt - 1; i >= 0; i--)
    printf("%d\n", res[i]);
}