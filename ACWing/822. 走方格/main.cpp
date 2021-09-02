#include <iostream>
using namespace std;

const int N = 15;
int a[N][N];
int n, m;

int main() {
    cin >> n >> m;
    a[0][0] = 1;
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m; j++) {
            if (i > 0) a[i][j] += a[i - 1][j];
            if (j > 0) a[i][j] += a[i][j - 1];
        }
    
    cout << a[n][m] << endl;

    return 0;
}