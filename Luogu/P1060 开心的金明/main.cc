#include <iostream>
using namespace std;

const int W = 30010, N = 27;
int ww, n;
int w[N], v[N];
int f[N][W];

int main() {
    scanf("%d%d", &ww, &n);
    for (int i = 1; i <= n; i++)
        scanf("%d%d", &w[i], &v[i]);

    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= ww; j++) {
            f[i][j] = f[i - 1][j];
            if (j >= w[i]) f[i][j] = max(f[i][j], f[i - 1][j - w[i]] + w[i] * v[i]);
        }
    printf("%d\n", f[n][ww]);

    return 0;
}