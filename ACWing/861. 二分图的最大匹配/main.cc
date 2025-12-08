#include <iostream>
#include <cstring>
using namespace std;

const int N = 510, M = 1e5 + 10;

int n1, n2, m;
int h[N], e[M], ne[M], idx;
int match[N];
bool vis[N];

#define add(a, b) e[idx] = b, ne[idx] = h[a], h[a] = idx++

bool dfs(int v) {
  for (int i = h[v]; ~i; i = ne[i]) {
    int j = e[i];
    if (!vis[j]) {
      vis[j] = true;
      if (!match[j] || dfs(match[j])) {
        match[j] = v;
        return true;
      }
    }
  }

  return false;
}

int main() {
  scanf("%d%d%d", &n1, &n2, &m);

  memset(h, -1, sizeof h);

  while (m--) {
    int a, b;
    scanf("%d%d", &a, &b);
    add(a, b);
  }

  int res = 0;
  for (int i = 1; i <= n1; i++) {
    memset(vis, false, sizeof vis);
    if (dfs(i)) res++;
  }
  printf("%d\n", res);
}