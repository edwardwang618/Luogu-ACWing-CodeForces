#include <iostream>
using namespace std;

const int N = 2010, mod = 1e9 + 7;

int f[N][N];

void init() {
    for (int i = 0; i < N; i++)
        for (int j = 0; j <= i; j++)
            if (!j) f[i][j] = 1;
            else f[i][j] = (f[i - 1][j] + f[i - 1][j - 1]) % mod;

}

int main() {
    int n;
    cin >> n;

    init();

    while (n--) {
        int a, b;
        cin >> a >> b;
        cout << f[a][b] << endl;
    }

    return 0;
}