#include <iostream>
using namespace std;

const int N = 510, INF = 1e9;
int a[N][N];
int n;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= i; j++) 
            cin >> a[i][j];

    for (int i = 2; i <= n; i++)
        for (int j = 1; j <= i; j++) {
            int t = -INF;
            if (j < i) t = max(t, a[i - 1][j]);
            if (j > 1) t = max(t, a[i - 1][j - 1]);

            a[i][j] += t;
        }

    int res = a[n][1];
    for (int i = 2; i <= n; i++) res = max(res, a[n][i]);

    cout << res << endl;

    return 0;
}