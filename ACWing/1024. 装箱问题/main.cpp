#include <iostream>
using namespace std;

const int N = 20020, M = 31;
int a[M];
bool f[M][N];
int n;

int main() {
    int V;
    cin >> V >> n;

    for (int i = 1; i <= n; i++) cin >> a[i];

    int res = V;
    f[0][0] = true;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= V; j++) {
            f[i][j] = f[i - 1][j];
            if (j >= a[i]) 
                f[i][j] |= f[i - 1][j - a[i]];
            if (f[i][j]) res = min(res, V - j);
        }
    }

    cout << res << endl;

    return 0;
}