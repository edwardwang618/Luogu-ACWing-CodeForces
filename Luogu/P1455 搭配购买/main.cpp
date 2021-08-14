#include <iostream>
#include <cstring>
using namespace std;

const int N = 1e4 + 10;
int n, m, vol;
int v[N], w[N];
int p[N];
int f[N];

int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main() {
    scanf("%d%d%d", &n, &m, &vol);
    for (int i = 1; i <= n; i++) scanf("%d%d", &v[i], &w[i]);
    for (int i = 1; i <= n; i++) p[i] = i;

    for (int i = 1; i <= m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        int pa = find(a), pb = find(b);
        if (pa != pb) {
            v[pb] += v[pa];
            w[pb] += w[pa];
            p[pa] = pb;
        }
    }

    for (int i = 1; i <= n; i++) 
        if (p[i] == i) 
            for (int j = vol; j >= v[i]; j--)
                f[j] = max(f[j], f[j - v[i]] + w[i]);
    
    printf("%d\n", f[vol]);
    return 0;
}