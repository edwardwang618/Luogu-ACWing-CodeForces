#include <iostream>
#include <cstring>
using namespace std;

const int N = 30, M = N * 60;
int n[4];
int a[N], f[M];
int res;

int main() {
    for (int t = 1; t <= 4; t++)
        scanf("%d", &n[t]);

    for (int t = 1; t <= 4; t++) {
        int sum = 0;
        for (int i = 1; i <= n[t]; i++) {
            scanf("%d", &a[i]);
            sum += a[i];
        }

        memset(f, 0, sizeof f);
        for (int i = 1; i <= n[t]; i++)
            for (int j = sum / 2; j >= a[i]; j--)
                f[j] = max(f[j], f[j - a[i]] + a[i]);

        res += sum - f[sum / 2];
    }

    printf("%d\n", res);

    return 0;
}