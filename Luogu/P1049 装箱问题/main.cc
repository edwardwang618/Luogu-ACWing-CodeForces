#include <iostream>
using namespace std;

const int V = 20010, N = 32;
int n, m;
int v[N];
int f[V];

int main() {
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &v[i]);

    for (int i = 1; i <= n; i++)
        for (int j = m; j >= v[i]; j--)
            f[j] = max(f[j], f[j - v[i]] + v[i]);

    printf("%d\n", m - f[m]);

    return 0;
}