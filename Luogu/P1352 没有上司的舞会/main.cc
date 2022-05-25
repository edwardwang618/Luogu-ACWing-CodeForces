#include <iostream>
#include <cstring>
using namespace std;

const int N = 6010;
int n;
int h[N], e[N], ne[N], idx;
int r[N];
bool is_boss[N];
int f[N][2];

void add(int a, int b) {
  e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void dfs(int u) {
  f[u][1] = r[u];
  for (int i = h[u]; ~i; i = ne[i]) {
    int v = e[i];
    dfs(v);
    f[u][1] += f[v][0];
    f[u][0] += max(f[v][0], f[v][1]);
  }
}

int main() {
  memset(h, -1, sizeof h);
  fill(is_boss, is_boss + N, true);

  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &r[i]);
  for (int i = 1; i <= n - 1; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    add(b, a);
    is_boss[a] = false;
  }

  int res = 0;
  for (int i = 1; i <= n; i++)
    if (is_boss[i]) {
      dfs(i);
      res += max(f[i][0], f[i][1]);
    }

  printf("%d\n", res);
}