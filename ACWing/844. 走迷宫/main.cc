#include <iostream>
#include <queue>
using namespace std;

using PII = pair<int, int>;

const int N = 110;
int a[N][N];
bool vis[N][N];
int n, m;
queue<PII> q;

int bfs() {
  int res = 0;
  if (m == 1 && n == 1) return res;
  q.push({0, 0});
  vis[0][0] = true;
  static int d[] = {1, 0, -1, 0, 1};
  
  while (q.size()) {
    res++;
    for (int i = q.size(); i; i--) {
      auto [x, y] = q.front(); q.pop();
      for (int k = 0; k < 4; k++) {
        int nx = x + d[k], ny = y + d[k + 1];
        if (0 <= nx && nx < m && 0 <= ny && ny < n && !vis[nx][ny] && !a[nx][ny]) {
          if (nx == m - 1 && ny == n - 1) return res;
          q.push({nx, ny});
          vis[nx][ny] = true;
        }
      }
    }
  }
  return -1;
}

int main() {
  scanf("%d%d", &m, &n);
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++) scanf("%d", &a[i][j]);

  printf("%d\n", bfs());
}