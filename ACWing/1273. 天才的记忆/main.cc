#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

const int N = 2e5 + 10, M = 19;
int n, m;
int f[N][M];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &f[i][0]);

    for (int j = 1; j < M; j++)
        for (int i = 1; i + (1 << j) - 1 <= n; i++)
            f[i][j] = max(f[i][j - 1], f[i + (1 << j - 1)][j - 1]);

    scanf("%d", &m);
    while (m--) {
        int l, r;
        scanf("%d%d", &l, &r);
        int k = log(r - l + 1) / log(2);
        printf("%d\n", max(f[l][k], f[r - (1 << k) + 1][k]));
    }

    return 0;
}