#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

const int N = 1e5 + 10;
int n, m;
int h[N], e[N], ne[N], idx;
int vis[N];
int res[N], cnt;

void add(int a, int b) {
  e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

bool dfs(int u) {
  vis[u] = 0;
  for (int i = h[u]; ~i; i = ne[i]) {
    int v = e[i];
    if (!vis[v]) return false;
    if (!~vis[v] && !dfs(v)) return false;
  }
  vis[u] = 1;
  res[++cnt] = u;
  return true;
}

int main() {
  scanf("%d%d", &n, &m);
  memset(h, -1, sizeof h);
  for (int i = 1; i <= m; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    add(a, b);
  }

  memset(vis, -1, sizeof vis);
  for (int i = 1; i <= n; i++)
    if (!~vis[i] && !dfs(i)) {
      cnt = 0;
      break;
    }
  
  if (cnt) for (int i = n; i; i--) printf("%d ", res[i]);
  else puts("-1");
}