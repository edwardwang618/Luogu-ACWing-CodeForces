#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

const int N = 40010, M = N << 1;
int n, m;
int h[N], e[M], ne[M], idx;
int root;
int dep[N], f[N][16];
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

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        if (b == -1) root = a;
        else add(a, b), add(b, a);
    }

    bfs();

    scanf("%d", &m);
    while (m--) {
        int a, b;
        scanf("%d%d", &a, &b);
        int p = lca(a, b);
        if (p == a) puts("1");
        else if (p == b) puts("2");
        else puts("0");
    }

    return 0;
}