#include <iostream>
using namespace std;

const int N = 110;
int v[N][N], w[N][N], s[N];
int n, m;
int f[N][N];

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
    for (int j = 1; j <= s[i]; j++) cin >> w[i][j] >> v[i][j];
  }

  for (int i = 1; i <= n; i++)
    for (int j = 0; j <= m; j++) {
      f[i][j] = f[i - 1][j];
      for (int k = 1; k <= s[i]; k++)
        if (j >= w[i][k])
          f[i][j] = max(f[i][j], f[i - 1][j - w[i][k]] + v[i][k]);
    }

  cout << f[n][m] << endl;
}