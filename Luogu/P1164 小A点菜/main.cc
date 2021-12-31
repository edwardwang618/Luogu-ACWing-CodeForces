#include <iostream>
using namespace std;

const int N = 110, M = 10010;
int n, m;
int a[N];
int f[N][M];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

    f[0][0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= m; j++) {
            f[i][j] = f[i - 1][j];
            if (j >= a[i]) f[i][j] += f[i - 1][j - a[i]];
        }

    printf("%d\n", f[n][m]);

    return 0;
}