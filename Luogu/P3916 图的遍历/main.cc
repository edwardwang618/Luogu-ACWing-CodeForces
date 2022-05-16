#include <iostream>
#include <cstring>
using namespace std;

const int N = 1e5 + 10;
int n, m;
int h[N], e[N], ne[N], idx;
int res[N];

void add(int a, int b) {
  e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void dfs(int u, int c) {
  if (res[u]) return;

  res[u] = c;
  for (int i = h[u]; ~i; i = ne[i]) {
    int v = e[i];
    dfs(v, max(v, c));
  }
}

int main() {
  memset(h, -1, sizeof h);

  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    add(b, a);
  }

  for (int i = n; i; i--)
    if (!res[i]) dfs(i, i);
  
  for (int i = 1; i <= n; i++)
    printf("%d ", res[i]);
}