#include <iostream>
#include <cstring>
using namespace std;

const int N = 510;
int n, m, k, cnt;
int d[] = {-1, 0, 1, 0, -1};
char a[N][N];
bool vis[N][N];

void dfs(int x, int y) {
  vis[x][y] = true;
  for (int i = 0; i < 4; i++) {
    int nx = x + d[i], ny = y + d[i + 1];
    if (0 <= nx && nx < n && 0 <= ny && ny < m && !vis[nx][ny] && a[nx][ny] != '#')
      dfs(nx, ny);
  }

  if (cnt) {
    a[x][y] = 'X';
    cnt--;
  }
}

int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < n; i++)
    scanf("%s", a[i]);
  
  cnt = k;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (cnt && a[i][j] == '.') {
        memset(vis, 0, sizeof vis);
        dfs(i, j);
      }
  
  for (int i = 0; i < n; i++)
    puts(a[i]);
}