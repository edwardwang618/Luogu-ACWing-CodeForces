#include <iostream>
using namespace std;

const int N = 110, M = 210, T = 210;
int n, mm, tt;
int m[N], t[N];
int f[N][M][T];

int main() {
    scanf("%d%d%d", &n, &mm, &tt);
    for (int i = 1; i <= n; i++)
        scanf("%d%d", &m[i], &t[i]);

    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= mm; j++)
            for (int k = 0; k <= tt; k++) {
                f[i][j][k] = f[i - 1][j][k];
                if (j >= m[i] && k >= t[i]) 
                    f[i][j][k] += f[i - 1][j - m[i]][k - t[i]] + 1;
            }

    printf("%d\n", f[n][mm][tt]);

    return 0;
}