#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

const int N = 1e4 + 10;
int n, m;
int root, chd[N][2];
int pre[N], in[N], map[N];
int c[N];
int dep[N], f[N][15];
int q[N];

int get(int x) {
  int l = 1, r = n;
  while (l < r) {
    int mid = l + (r - l + 1 >> 1);
    if (x >= c[mid]) l = mid;
    else r = mid - 1;
  }

  if (c[l] != x) return -1;
  return l;
}

int dfs(int pl, int pr, int il, int ir) {
  if (pl > pr) return 0;
  int u = pre[pl], lc = map[u] - il, rc = ir - map[u];
  chd[u][0] = dfs(pl + 1, pl + lc, il, map[u] - 1);
  chd[u][1] = dfs(pl + lc + 1, pr, map[u] + 1, ir);
  return u;
}

void bfs() {
  memset(dep, -1, sizeof dep);
  dep[root] = 0;
  int hh = 0, tt = 0;
  q[tt++] = root;
  while (hh < tt) {
    int t = q[hh++];
    for (int i = 0; i <= 1; i++) {
      int v = chd[t][i];
      if (v && dep[v] == -1) {
        dep[v] = dep[t] + 1;
        f[v][0] = t;
        for (int k = 1; 1 << k <= dep[v]; k++)
          f[v][k] = f[f[v][k - 1]][k - 1];
        
        q[tt++] = v;
      }
    }
  }
}

int lca(int a, int b) {
  if (dep[a] < dep[b]) swap(a, b);
  for (int k = 0, diff = dep[a] - dep[b]; 1 << k <= diff; k++)
    if (diff >> k & 1) a = f[a][k];
  
  if (a == b) return a;

  for (int k = log2(dep[a]); k >= 0; k--)
    if (f[a][k] != f[b][k])
      a = f[a][k], b = f[b][k];
  
  return f[a][0];
}

int main() {
  scanf("%d%d", &m, &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &in[i]);
    c[i] = in[i];
  }
  for (int i = 1; i <= n; i++) scanf("%d", &pre[i]);
  sort(c + 1, c + n + 1);
  for (int i = 1; i <= n; i++) {
    pre[i] = get(pre[i]), in[i] = get(in[i]);
    map[in[i]] = i;
  }

  root = dfs(1, n, 1, n);
  bfs();

  while (m--) {
    int a, b;
    scanf("%d%d", &a, &b);
    int x = a, y = b;
    a = get(a), b = get(b);
    if (a == -1 && b == -1)
      printf("ERROR: %d and %d are not found.\n", x, y);
    else if (a == -1)
      printf("ERROR: %d is not found.\n", x);
    else if (b == -1)
      printf("ERROR: %d is not found.\n", y);
    else {
      int p = lca(a, b);
      if (p == a) printf("%d is an ancestor of %d.\n", x, y);
      else if (p == b) printf("%d is an ancestor of %d.\n", y, x);
      else printf("LCA of %d and %d is %d.\n", x, y, c[p]);
    }
  }
}