#include <iostream>
#include <cstring>
using namespace std;

const int N = 100010, K = 110;
int n, k;
int a[N], f[N][K][2];

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];

    int res = 0;
    if (k >= n / 2) {
        for (int i = 2; i <= n; i++)
            res += max(0, a[i] - a[i - 1]);

        cout << res << endl;
        return 0;
    }

    memset(f, -0x3f, sizeof f);
    f[0][0][0] = 0;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            f[i][j][0] = max(f[i - 1][j][0], f[i - 1][j][1] + a[i]);
            f[i][j][1] = f[i - 1][j][1];
            if (j >= 1) f[i][j][1] = max(f[i][j][1], f[i - 1][j - 1][0] - a[i]);
        }
    }

    cout << f[n][k][0] << endl;

    return 0;
}