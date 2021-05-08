#include <iostream>
#include <cstring>
using namespace std;

const int N = 5e5 + 10, M = 2 * N;
int n, qu, r;
int h[N], e[M], ne[M], idx;
int depth[N], fa[N][25];
int q[N];

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void bfs() {
    memset(depth, 0x3f, sizeof depth);
    depth[0] = 0, depth[r] = 1;

    int hh = 0, tt = 0;
    q[tt++] = r;
    while (hh < tt) {
        int t = q[hh++];
        for (int i = h[t]; ~i; i = ne[i]) {
            int j = e[i];
            if (depth[j] > depth[t] + 1) {
                depth[j] = depth[t] + 1;
                q[tt++] = j;

                fa[j][0] = t;
                for (int k = 1; k <= 21; k++) 
                    fa[j][k] = fa[fa[j][k - 1]][k - 1];
            }
        }
    }
}

int lca(int a, int b) {
    if (depth[a] < depth[b]) swap(a, b);
    for (int k = 21; k >= 0; k--) 
        if (depth[fa[a][k]] >= depth[b])
            a = fa[a][k];

    if (a == b) return a;
    for (int k = 21; k >= 0; k--)
        if (fa[a][k] != fa[b][k]) 
            a = fa[a][k], b = fa[b][k];

    return fa[a][0];
}

int main() {
    scanf("%d%d%d", &n, &qu, &r);
    memset(h, -1, sizeof h);
    for (int i = 0; i < n - 1; i++) {
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