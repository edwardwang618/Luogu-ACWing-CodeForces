#include <iostream>
using namespace std;

const int N = 15;
int w[N][N], f[2 * N + 1][N][N];

int main() {
    int n;
    cin >> n;
    while (1) {
        int x, y, v;
        cin >> x >> y >> v;
        if (x == 0 && y == 0 && v == 0) break;
        w[x][y] = v;
    }

    for (int k = 2; k <= n * 2; k++) 
        for (int i1 = 1; i1 <= n; i1++) 
            for (int i2 = 1; i2 <= n; i2++) {
                int j1 = k - i1, j2 = k - i2;
                if (1 <= j1 && j1 <= n && 1 <= j2 && j2 <= n) {
                    int t = i1 == i2 ? w[i1][j1] : w[i1][j1] + w[i2][j2];
                    int &v = f[k][i1][i2];
                    v = max(v, f[k - 1][i1 - 1][i2 - 1] + t);
                    v = max(v, f[k - 1][i1][i2 - 1] + t);
                    v = max(v, f[k - 1][i1 - 1][i2] + t);
                    v = max(v, f[k - 1][i1][i2] + t);
                }
            }

    cout << f[n * 2][n][n] << endl;
    return 0;
}