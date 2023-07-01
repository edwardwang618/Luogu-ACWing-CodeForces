#include <iostream>
#include <cstring>
using namespace std;

const int N = 1e4 + 10, M = 1e5 + 10;
int n, m;
int h[N], e[M], ne[M], idx;

#define add(a, b) e[idx] = b, ne[idx] = h[a], h[a] = idx++

void dfs(int u) {
  for (int i = h[u]; ~i; i = h[u]) {
    h[u] = ne[i];
    dfs(e[i]);
  }
  printf("%d\n", u);
}

int main() {
  memset(h, -1, sizeof h);
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    add(a, b), add(b, a);
  }

  dfs(1);
}