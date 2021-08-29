#include <iostream>
using namespace std;

const int N = 110;
int a[N][N];

int main() {
    a[0][0] = 1;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (i > 0) a[i][j] = a[j][i] = a[i - 1][j] << 1;
            else if (j > 0) a[i][j] = a[i][j - 1] << 1;

    int n;
    while (cin >> n, n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                printf("%d ", a[i][j]);
            puts("");
        }
        puts("");
    }

    return 0;
}