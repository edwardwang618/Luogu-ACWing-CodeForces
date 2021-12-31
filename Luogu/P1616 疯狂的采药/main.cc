#include <iostream>
using namespace std;

const int V = 1e7 + 10, N = 1e4 + 10;
int n, m;
int v[N], w[N];
long f[V];

int main() {
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= n; i++)
        scanf("%d%d", &v[i], &w[i]);

    for (int i = 1; i <= n; i++)
        for (int j = v[i]; j <= m; j++)
            f[j] = max(f[j], f[j - v[i]] + w[i]);

    printf("%ld\n", f[m]);

    return 0;
}