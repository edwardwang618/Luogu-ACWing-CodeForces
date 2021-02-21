#include <iostream>
using namespace std;

const int N = 60;
int m, n;
int a[N][N], f[2 * N + 1][N + 1][N + 1];

int main() {
    cin >> m >> n;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];

    for (int k = 2; k <= 2 * N; k++)
        for (int i1 = 1; i1 <= m; i1++)
            for (int i2 = 1; i2 <= m; i2++) {
                int j1 = k - i1, j2 = k - i2;
                if (1 <= j1 && j1 <= n && 1 <= j2 && j2 <= n) {
                    int t = i1 == i2 ? a[i1][j1] : a[i1][j1] + a[i2][j2];
                    int &x = f[k][i1][i2];
                    x = max(x, f[k - 1][i1 - 1][i2 - 1] + t);
                    x = max(x, f[k - 1][i1 - 1][i2] + t);
                    x = max(x, f[k - 1][i1][i2 - 1] + t);
                    x = max(x, f[k - 1][i1][i2] + t);
                }
            }
    
    cout << f[m + n][m][m] << endl;

    return 0;
}