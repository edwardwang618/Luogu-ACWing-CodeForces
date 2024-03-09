#include <iostream>
using namespace std;

const int N = 110;
int n;
int a[N][N], s[N][N];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      scanf("%d", &a[i][j]);
      s[i][j] = s[i - 1][j] + a[i][j];
    }
  
  int res = -2e9;
  for (int i = 1; i <=n; i++)
    for (int j = i; j <= n; j++) {
      int cur = 0;
      for (int k = 1; k <= n; k++) {
        cur = max(cur, 0) + s[j][k] - s[i - 1][k];
        res = max(res, cur);
      }
    }
  printf("%d\n", res);
}