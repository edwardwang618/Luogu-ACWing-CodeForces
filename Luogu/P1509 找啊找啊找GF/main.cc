#include<iostream>
using namespace std;

const int N = 110;
int n, m, r;
int rp[N], tim[N], rmb[N];
int fn[N][N], ft[N][N];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d%d%d", &rmb[i], &rp[i], &tim[i]);

    scanf("%d%d", &m, &r);
    for (int i = 1; i <= n; i++)
        for (int j = m; j >= rmb[i]; j--)
            for (int k = r; k >= rp[i]; k--) {
                if (fn[j][k] < fn[j - rmb[i]][k - rp[i]] + 1) {
                    fn[j][k] = fn[j - rmb[i]][k - rp[i]] + 1;
                    ft[j][k] = ft[j - rmb[i]][k - rp[i]] + tim[i];
                }

                if (fn[j][k] == fn[j - rmb[i]][k - rp[i]] + 1)
                    ft[j][k] = min(ft[j][k], ft[j - rmb[i]][k - rp[i]] + tim[i]);
            }

    printf("%d\n", ft[m][r]);

    return 0;
}