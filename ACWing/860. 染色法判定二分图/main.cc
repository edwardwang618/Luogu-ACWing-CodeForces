#include <iostream>
#include <cstring>
using namespace std;

const int N = 1e5 + 10, M = N << 1;
int n, m;
int h[N], e[M], ne[M], idx;
int col[N];

#define add(a, b) \
  e[idx] = b, ne[idx] = h[a], h[a] = idx++

bool dfs(int u, int c) {
  col[u] = c;
  for (int i = h[u]; ~i; i = ne[i]) {
    int v = e[i];
    if (col[v] == c) return false;
    if (!~col[v] && !dfs(v, c ^ 1)) return false;
  }
  return true;
}

int main() {
  scanf("%d%d", &n, &m);
  memset(h, -1, sizeof h);
  while (m--) {
    int a, b;
    scanf("%d%d", &a, &b);
    add(a, b), add(b, a);
  }

  bool res = true;
  memset(col, -1, sizeof col);
  for (int i = 1; i <= n; i++)
    if (!~col[i] && !dfs(i, 0)) {
      res = false;
      break;
    }
  
  puts(res ? "Yes" : "No");
}