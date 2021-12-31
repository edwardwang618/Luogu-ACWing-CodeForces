#include <iostream>
using namespace std;

const int N = 110, M = 210, T = 210;
int n, mm, tt;
int m[N], t[N];
int f[M][T];

int main() {
    scanf("%d%d%d", &n, &mm, &tt);
    for (int i = 1; i <= n; i++)
        scanf("%d%d", &m[i], &t[i]);

    for (int i = 1; i <= n; i++)
        for (int j = mm; j >= m[i]; j--)
            for (int k = tt; k >= t[i]; k--) {
                f[j][k] = max(f[j][k], f[j - m[i]][k - t[i]] + 1);
            }

    printf("%d\n", f[mm][tt]);

    return 0;
}