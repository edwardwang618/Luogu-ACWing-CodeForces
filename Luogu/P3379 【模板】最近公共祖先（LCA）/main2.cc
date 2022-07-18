#include <iostream>
#include <cstring>
using namespace std;

const int N = 5e5 + 10, M = N << 1;
int n, qu;
int h[N], e[M], ne[M], idx;
int dep[N], son[N], top[N], sz[N], fa[N];
int root;

void add(int a, int b) {
  e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void dfs1(int u, int from, int depth) {
  dep[u] = depth, sz[u] = 1, fa[u] = from;
  for (int i = h[u]; ~i; i = ne[i]) {
    int v = e[i];
    if (v == from) continue;
    dfs1(v, u, depth + 1);
    sz[u] += sz[v];
    if (sz[son[u]] < sz[v]) son[u] = v;
  }
}

void dfs2(int u, int from, int t) {
  top[u] = t;
  if (!son[u]) return;
  dfs2(son[u], u, t);
  for (int i = h[u]; ~i; i = ne[i]) {
    int v = e[i];
    if (v == son[u] || v == from) continue;
    dfs2(v, u, v);
  }
}

int lca(int u, int v) {
  while (top[u] != top[v]) {
    // 谁的重链头深度深，谁就向上跳
    if (dep[top[u]] < dep[top[v]]) swap(u, v);
    u = fa[top[u]];
  }
  return dep[u] < dep[v] ? u : v;
}

int main() {
  memset(h, -1, sizeof h);
  scanf("%d%d%d", &n, &qu, &root);
  for (int i = 1; i <= n - 1; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    add(a, b), add(b, a);
  }

  dfs1(root, -1, 0);
  dfs2(root, -1, root);

  for (int i = 0; i < qu; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    printf("%d\n", lca(a, b));
  }
}