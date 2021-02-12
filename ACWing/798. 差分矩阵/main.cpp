#include <iostream>
using namespace std;

const int N = 1010;
int a[N][N], d[N][N];
int n, m, q;

int main() {
    cin >> n >> m >> q;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];

    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++) {
            d[i][j] += a[i][j];
            d[i + 1][j] -= a[i][j];
            d[i][j + 1] -= a[i][j];
            d[i + 1][j + 1] += a[i][j];
        }

    while (q--) {
        int x1, y1, x2, y2, c;
        cin >> x1 >> y1 >> x2 >> y2 >> c;
        d[x1 - 1][y1 - 1] += c;
        d[x1 - 1][y2] -= c;
        d[x2][y1 - 1] -= c;
        d[x2][y2] += c;
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i > 0) d[i][j] += d[i - 1][j];
            if (j > 0) d[i][j] += d[i][j - 1];
            if (i > 0 && j > 0) d[i][j] -= d[i - 1][j - 1];
            cout << d[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}