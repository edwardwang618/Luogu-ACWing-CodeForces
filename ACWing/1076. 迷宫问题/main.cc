#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
using PII = pair<int, int>;

const int N = 1010;
int a[N][N];
PII pre[N][N];
int n;

void bfs(int x, int y) {
  static int d[] = {1, 0, -1, 0, 1};
  memset(pre, -1, sizeof pre);
  queue<PII> q;
  q.push({x, y});

  pre[x][y] = {x, y};
  while (q.size()) {
    auto t = q.front();
    q.pop();
    x = t.first, y = t.second;
    for (int i = 0; i < 4; i++) {
      int nx = x + d[i], ny = y + d[i + 1];
      if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
      if (a[nx][ny]) continue;
      if (pre[nx][ny].first != -1) continue;

      q.push({nx, ny});
      pre[nx][ny] = t;

      if (!nx && !ny) return;
    }
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) scanf("%d", &a[i][j]);

  bfs(n - 1, n - 1);
  PII end = {0, 0};

  while (1) {
    printf("%d %d\n", end.first, end.second);
    if (end.first == n - 1 && end.second == n - 1) break;
    end = pre[end.first][end.second];
  }
}