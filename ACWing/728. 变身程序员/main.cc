#include <iostream>
#include <sstream>
using namespace std;
using PII = pair<int, int>;

int m, n;
int a[15][15];
PII q[110];

int main() {
  string s;
  while (getline(cin, s)) {
    stringstream ss(s);
    n = 0;
    while (ss >> a[m][n++]);
    m++;
  }

  int hh = 0, tt = 0;
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      if (a[i][j] == 2) q[tt++] = {i, j};

  int d[] = {-1, 0, 1, 0, -1};
  int res = 0;
  while (hh < tt) {
    res++;
    for (int i = tt - hh; i; i--) {
      auto [x, y] = q[hh++];
      for (int k = 0; k < 4; k++) {
        int nx = x + d[k], ny = y + d[k + 1];
        if (0 <= nx && nx < m && 0 <= ny && ny < n && a[nx][ny] == 1) {
          a[nx][ny] = 2;
          q[tt++] = {nx, ny};
        }
      }
    }
  }

  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      if (a[i][j] == 1) {
        puts("-1");
        return 0;
      }

  printf("%d\n", res - 1);
}