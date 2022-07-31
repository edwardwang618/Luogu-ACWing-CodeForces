#include <iostream>
#include <cstring>
using namespace std;

const int N = 55, M = 2550;
int n, m, rcnt, ccnt;
char a[N][N];
int rid[N][N], cid[N][N];
int match[M];
bool vis[M];
int h[M], e[M], ne[M], idx;

void add(int a, int b) {
  e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

bool dfs(int u) {
  for (int i = h[u]; ~i; i = ne[i]) {
    int v = e[i];
    if (vis[v]) continue;
    vis[v] = true;
    if (!match[v] || dfs(match[v])) {
      match[v] = u;
      return true;
    }
  }
  return false;
}

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; t++) {
    memset(h, -1, sizeof h);
    idx = 0;
    memset(rid, 0, sizeof rid);
    memset(cid, 0, sizeof cid);
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= m; i++) scanf("%s", a[i] + 1);

    rcnt = 1, ccnt = 1;
    for (int i = 1; i <= m; i++)
      for (int j = 1; j <= n; j++) {
        if (a[i][j] != '#') {
          while (j <= n && a[i][j] != '#') rid[i][j++] = rcnt;
          rcnt++;
        }
      }

    for (int j = 1; j <= n; j++)
      for (int i = 1; i <= m; i++) {
        if (a[i][j] != '#') {
          while (i <= m && a[i][j] != '#') cid[i++][j] = ccnt;
          ccnt++;
        }
      }

    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= m; ++j)
        if (a[i][j] == 'o') add(rid[i][j], cid[i][j]);

    int res = 0;
    memset(match, 0, sizeof match);
    for (int i = 1; i < rcnt; ++i) {
      memset(vis, 0, sizeof vis);
      if (dfs(i)) res++;
    }

    printf("Case :%d\n%d\n", t, res);
  }
}