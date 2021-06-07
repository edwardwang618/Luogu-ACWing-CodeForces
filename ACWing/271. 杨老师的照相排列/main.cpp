#include <iostream>
#include <cstring>
using namespace std;

const int N = 31;
int n;
long f[N][N][N][N][N];

int main() {
    while (cin >> n, n) {
        int a[5] = {0};
        for (int i = 0; i < n; i++) cin >> a[i];
        memset(f, 0, sizeof f);
        f[0][0][0][0][0] = 1;

        for (int x0 = 0; x0 <= a[0]; x0++)
            for (int x1 = 0; x1 <= min(x0, a[1]); x1++)
                for (int x2 = 0; x2 <= min(x1, a[2]); x2++)
                    for (int x3 = 0; x3 <= min(x2, a[3]); x3++)
                        for (int x4 = 0; x4 <= min(x3, a[4]); x4++) {
                            long &v = f[x0][x1][x2][x3][x4];
                            if (x0 && x0 >= x1 + 1) v += f[x0 - 1][x1][x2][x3][x4];
                            if (x1 && x1 >= x2 + 1) v += f[x0][x1 - 1][x2][x3][x4];
                            if (x2 && x2 >= x3 + 1) v += f[x0][x1][x2 - 1][x3][x4];
                            if (x3 && x3 >= x4 + 1) v += f[x0][x1][x2][x3 - 1][x4];
                            if (x4) v += f[x0][x1][x2][x3][x4 - 1];
                        }

        cout << f[a[0]][a[1]][a[2]][a[3]][a[4]] << endl;
    }

    return 0;
}