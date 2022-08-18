#include <iostream>
using namespace std;

const int N = 210;
int n;
int a[N];
int f[N][N];

int main() {
    cin >> n;
    for (int i = 1; i <= 2 * n; i++)
        if (i <= n) cin >> a[i];
        else a[i] = a[i - n];

    int res = 0;
    for (int l = 3; l <= n + 1; l++)
        for (int i = 1; i + l - 1 <= 2 * n; i++) {
            int j = i + l - 1;
            for (int k = i + 1; k <= j - 1; k++)
                f[i][j] = max(f[i][j], f[i][k] + f[k][j] + a[i] * a[k] * a[j]);
            
            if (l == n + 1) res = max(res, f[i][j]);
        }

    cout << res << endl;

    return 0;
}