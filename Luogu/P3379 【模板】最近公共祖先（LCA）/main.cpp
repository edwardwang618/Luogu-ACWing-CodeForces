#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

const int N = 5e5 + 10, M = N << 1;
int n, m, qu, root;
int h[N], e[M], ne[M], idx;
int dep[N], f[N][25];
int q[N];

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void bfs() {
    memset(dep, -1, sizeof dep);
    dep[root] = 0;
    int hh = 0, tt = 0;
    q[tt++] = root;
    while (hh < tt) {
        int t = q[hh++];
        for (int i = h[t]; ~i; i = ne[i]) {
            int v = e[i];
            if (dep[v] == -1) {
                dep[v] = dep[t] + 1;
                q[tt++] = v;
                f[v][0] = t;
                for (int k = 1; 1 << k <= dep[v]; k++) 
                    f[v][k] = f[f[v][k - 1]][k - 1];
            }
        }
    }
}

int lca(int a, int b) {
    if (dep[a] < dep[b]) swap(a, b);
    for (int k = 0, diff = dep[a] - dep[b]; 1 << k <= diff; k++)
        if (diff >> k & 1)
            a = f[a][k];

    if (a == b) return a;

    for (int k = log2(dep[a]); k >= 0; k--)
        if (f[a][k] != f[b][k])
            a = f[a][k], b = f[b][k];
    
    return f[a][0];
}

int main() {
    memset(h, -1, sizeof h);

    scanf("%d%d%d", &n, &qu, &root);
    for (int i = 1; i <= n - 1; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b), add(b, a);
    }

    bfs();

    for (int i = 0; i < qu; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%d\n", lca(a, b));
    }

    return 0;
}