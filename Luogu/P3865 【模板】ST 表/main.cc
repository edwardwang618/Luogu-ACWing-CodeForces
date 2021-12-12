#include <iostream>
#include <cmath>
using namespace std;

const int N = 1e5 + 10;
int n, m;
int f[N][20];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &f[i][0]);
    int J = log2(n);
    for (int j = 1; j <= J; j++)
        for (int i = 1; i + (1 << j) - 1 <= n; i++)
            f[i][j] = max(f[i][j - 1], f[i + (1 << j - 1)][j - 1]);

    int l, r;
    while (m--) {
        scanf("%d%d", &l, &r);
        int k = log2(r - l + 1);
        printf("%d\n", max(f[l][k], f[r - (1 << k) + 1][k]));
    }

    return 0;
}