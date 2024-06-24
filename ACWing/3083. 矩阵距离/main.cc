#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

const int N = 1010;
int m, n;
char s[N][N];
int res[N][N];
queue<pair<int, int>> q;

void bfs() {
  memset(res, -1, sizeof res);
  for (int i = 1; i <= m; i++)
    for (int j = 1; j <= n; j++)
      if (s[i][j] == '1') {
        q.push({i, j});
        res[i][j] = 0;
      }

  static int d[] = {-1, 0, 1, 0, -1};
  while (q.size()) {
    auto p = q.front();
    q.pop();
    int x = p.first, y = p.second;
    for (int k = 0; k < 4; k++) {
      int nx = x + d[k], ny = y + d[k + 1];
      if (1 <= nx && nx <= m && 1 <= ny && ny <= n && !~res[nx][ny]) {
        res[nx][ny] = res[x][y] + 1;
        q.push({nx, ny});
      }
    }
  }
}

int main() {
  scanf("%d%d", &m, &n);
  for (int i = 1; i <= m; i++) scanf("%s", s[i] + 1);
  bfs();
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) printf("%d ", res[i][j]);
    puts("");
  }
}