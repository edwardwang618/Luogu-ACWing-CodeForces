#include <iostream>
#include <queue>
using namespace std;
using PII = pair<int, int>;

#define x first
#define y second

const int N = 110;
int m, n;
int mx, my;
char g[N][N];

int bfs() {
  queue<PII> q;
  q.push({mx, my});
  int res = 0;
  while (q.size()) {
    res++;
    for (int _ = q.size(); _; _--) {
      auto t = q.front(); q.pop();
      int x = t.x, y = t.y;
      for (int dx = -1; dx <= 1; dx++)
        for (int dy = -1; dy <= 1; dy++) {
          if (!dx && !dy) continue;
          int nx = x + dx, ny = y + dy;
          if (1 <= nx && nx <= m && 1 <= ny && ny <= n && g[nx][ny] == '.') {
            g[nx][ny] = 'M';
            q.push({nx, ny});
          }
        }
    }
  }

  return res;
}

int main() {
  scanf("%d%d%d%d", &n, &m, &my, &mx);
  for (int i = 1; i <= m; i++) scanf("%s", g[i] + 1);
  mx = m - mx + 1;
  g[mx][my] = 'M';

  printf("%d\n", bfs() - 1);
}