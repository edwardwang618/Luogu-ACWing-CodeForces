#include <iostream>
#include <cstring>
using namespace std;

const int N = 5e4 + 10, M = N << 1, K = 510;
int n, m;
int h[N], e[M], ne[M], idx;
int f[N][K];
int res;

void add(int a, int b) {
  e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void dfs(int u, int from) {
  f[u][0] = 1;
  for (int i = h[u]; ~i; i = ne[i]) {
    int v = e[i];
    if (v == from) continue;
    dfs(v, u);
    for (int j = 0; j < m; j++) res += f[u][j] * f[v][m - 1 - j];
    for (int j = 0; j < m; j++) f[u][j + 1] += f[v][j];
  }
}

int main() {
  memset(h, -1, sizeof h);
  scanf("%d%d", &n, &m);
  for (int i = 1; i < n; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    add(a, b), add(b, a);
  }

  dfs(1, -1);
  printf("%d\n", res);
}