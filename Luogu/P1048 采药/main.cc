#include <iostream>
using namespace std;

const int N = 110, V = 1010;
int n, m;
int v[N], w[N];
int f[V];

int main() {
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= n; i++) 
        scanf("%d%d", &w[i], &v[i]);

    for (int i = 1; i <= n; i++)
        for (int j = m; j >= w[i]; j--)
            f[j] = max(f[j], f[j - w[i]] + v[i]);
    
    printf("%d\n", f[m]);

    return 0;
}