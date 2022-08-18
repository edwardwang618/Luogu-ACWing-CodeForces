#include <iostream>
using namespace std;

const int N = 110;
int a[N][N];

int main() {
    for (int i = 0; i < N; i++)
        for (int j = 0, s = 1; i + j < N; j++)
            a[i][i + j] = a[i + j][i] = s++;

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