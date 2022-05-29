#include <iostream>
#include <unordered_map>
using namespace std;

const int N = 110;
int n, m;
char a[N], b[N];
unordered_map<char, int> mp = {{'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}, {'-', 4}};
int A[5][5] = {
  {5, -1, -2, -1, -3},
  {-1, 5, -3, -2, -4},
  {-2, -3, 5, -2, -2},
  {-1, -2, -2, 5, -1},
  {-3, -4, -2, -1, 0}
};
int f[N][N];

int main() {
  scanf("%d %s", &n, a + 1);
  scanf("%d %s", &m, b + 1);

  for (int i = 1; i <= n; i++) f[i][0] = f[i - 1][0] + A[mp[a[i]]][4];
  for (int i = 1; i <= m; i++) f[0][i] = f[0][i - 1] + A[4][mp[b[i]]];

  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (a[i] == b[j]) f[i][j] = f[i - 1][j - 1] + 5;
      else {
        int x = mp[a[i]], y = mp[b[j]];
        f[i][j] = f[i - 1][j - 1] + A[x][y];
        f[i][j] = max(f[i][j], f[i - 1][j] + A[x][4]);
        f[i][j] = max(f[i][j], f[i][j - 1] + A[y][4]);
      }

  printf("%d\n", f[n][m]);
}