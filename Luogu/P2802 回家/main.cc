#include <iostream>
#include <queue>
using namespace std;

const int N = 15;
int m, n;
int a[N][N];
int sx, sy, hx, hy;
struct Node {
  int x, y;
  int e;
};
queue<Node> q;
bool vis[N][N][10];

int bfs() {
  Node node = {sx, sy, 6};
  vis[sx][sy][6] = true;
  q.push(node);
  static int d[] = {-1, 0, 1, 0, -1};
  int res = 0;
  while (q.size()) {
    res++;
    for (int _ = q.size(); _; _--) {
      auto t = q.front(); q.pop();
      int x = t.x, y = t.y, e = t.e;
      if (e == 1) continue;
      for (int i = 0; i < 4; i++) {
        int nx = x + d[i], ny = y + d[i + 1];
        if (1 <= nx && nx <= m && 1 <= ny && ny <= n) {
          if (nx == hx && ny == hy) return res;
          if (!a[nx][ny]) continue;
          Node ne = {nx, ny, a[nx][ny] == 4 ? 6 : e - 1};
          if (vis[nx][ny][ne.e]) continue;
          vis[nx][ny][ne.e] = true;
          q.push(ne);
        }
      }
    }
  }

  return -1;
}

int main() {
  scanf("%d%d", &m, &n);
  for (int i = 1; i <= m; i++)
    for (int j = 1; j <= n; j++) {
      int x;
      scanf("%d", &x);
      a[i][j] = x;
      if (x == 2)
        sx = i, sy = j;
      else if (x == 3)
        hx = i, hy = j;
    }

  printf("%d\n", bfs());
}