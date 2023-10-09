#include <iostream>
#include <cstring>
using namespace std;

const int N = 10;
char g[N][N];
int n, k;
bool col[N];

int dfs(int x, int cnt) {
  if (cnt == k) return 1;

  if (x > n) return 0;
  int res = 0;
  for (int i = 1; i <= n; i++)
    if (g[x][i] == '#' && !col[i]) {
      cnt++;
      col[i] = true;
      res += dfs(x + 1, cnt);
      cnt--;
      col[i] = false;
    }
  res += dfs(x + 1, cnt);
  return res;
}

int main() {
  while (scanf("%d%d", &n, &k)) {
    if (!~n && !~k) break;
    memset(col, 0, sizeof col);
    for (int i = 1; i <= n; i++) scanf("%s", g[i] + 1);
    printf("%d\n", dfs(1, 0));
  }
}