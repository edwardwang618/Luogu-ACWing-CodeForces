#include <iostream>
#include <cstring>
using namespace std;

const int N = 410;
int n, a[N], s[N];
int f[N][N], g[N][N];

int main() {
    cin >> n;
    for (int i = 1; i < 2 * n; i++) {
        if (i <= n) cin >> a[i];
        else a[i] = a[i - n];

        s[i] = s[i - 1] + a[i];
    }

    memset(f, 0x3f, sizeof f);

    int r1 = 0x3f3f3f3f, r2 = 0;
    for (int l = 1; l <= n; l++)
        for (int i = 1; i + l - 1 < 2 * n; i++) {
            int j = i + l - 1;
            if (l == 1) {
                f[i][j] = 0;
                continue;
            }

            for (int k = i; k < j; k++) {
                f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j] + s[j] - s[i - 1]);
                g[i][j] = max(g[i][j], g[i][k] + g[k + 1][j] + s[j] - s[i - 1]);
            }

            if (l == n) {
                r1 = min(r1, f[i][j]);
                r2 = max(r2, g[i][j]);
            }
        }

    cout << r1 << endl;
    cout << r2 << endl;

    return 0;
}