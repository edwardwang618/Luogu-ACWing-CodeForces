#include <iostream>
using namespace std;

int m, n;
int a[110][110];

int main() {
    cin >> m >> n;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[j][i];

    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= 1; j--)
            cout << a[i][j] << ' ';
        cout << endl;
    }

    return 0;
}