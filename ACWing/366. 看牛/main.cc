#include <iostream>
#include <cstring>
using namespace std;

const int N = 1e4 + 10, M = 5e4 * 2 + 10;
int n, m;
int h[N], e[M], ne[M], idx;
bool used[M];
int res[M], cnt;

void add(int a, int b) {
  e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void dfs(int u) {
  for (int i = h[u]; ~i; i = h[u]) {
    if (used[i]) {
      h[u] = ne[i];
      continue;
    }

    int v = e[i];
    h[u] = ne[i];
    dfs(v);
  }

  res[++cnt] = u;
}

int main() {
  memset(h, -1, sizeof h);
  scanf("%d%d", &n, &m);
  while (m--) {
    int a, b;
    scanf("%d%d", &a, &b);
    add(a, b), add(b, a);
  }

  dfs(1);
  for (int i = cnt; i; i--) printf("%d\n", res[i]);
}