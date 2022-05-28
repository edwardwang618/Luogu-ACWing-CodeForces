#include <iostream>
#include <vector>
#define v first
#define w second
using namespace std;
using PII = pair<int, int>;
const int M = 32010, N = 70;

int n, m;
PII g[N];
vector<PII> son[N];
int f[N][M];

int main() {
  cin >> m >> n;
  for (int i = 1; i <= n; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    if (!c) g[i] = {a, a * b};
    else son[c].push_back({a, a * b});
  }

  for (int i = 1; i <= n; i++) {
    for (int j = g[i].v; j <= m; j++)
      f[i][j] = max(f[i][j], f[i - 1][j - g[i].v] + g[i].w);

    for (int k = 0; k < son[i].size(); k++)
      for (int j = m; j >= son[i][k].v; j--)
        if (f[i][j - son[i][k].v] > 0)
          f[i][j] = max(f[i][j], f[i][j - son[i][k].v] + son[i][k].w);

    for (int j = 0; j <= m; j++)
      f[i][j] = max(f[i][j], f[i - 1][j]);
  }

  cout << f[n][m] << endl;
}