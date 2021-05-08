#include <iostream>
#include <cstring>
using namespace std;

const int N = 100010, M = 2 * N;
int n, m;
int h[N], e[M], ne[M], idx;
int depth[N], fa[N][17];
int d[N], q[N];

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void bfs() {
    memset(depth, 0x3f, sizeof depth);
    depth[0] = 0, depth[1] = 1;
    int hh = 0, tt = 0;
    q[tt++] = 1;
    while (hh < tt) {
        int t = q[hh++];
        for (int i = h[t]; ~i; i = ne[i]) {
            int j = e[i];
            if (depth[j] > depth[t] + 1) {
                depth[j] = depth[t] + 1;
                
                fa[j][0] = t;
                for (int k = 1; k < 17; k++) 
                    fa[j][k] = fa[fa[j][k - 1]][k - 1];

                q[tt++] = j;
            }
        }
    }   
}

int lca(int a, int b) {
    if (depth[a] < depth[b]) swap(a, b);
    for (int k = 16; k >= 0; k--)
        if (depth[fa[a][k]] >= depth[b])
            a = fa[a][k];
    
    if (a == b) return a;
    for (int k = 16; k >= 0; k--)
        if (fa[a][k] != fa[b][k])
            a = fa[a][k], b = fa[b][k];

    return fa[a][0];
}

int dfs(int u, int father, int& res) {
    int ans = d[u];
    for (int i = h[u]; ~i; i = ne[i]) {
        int j = e[i];
        if (j != father) {
            int t = dfs(j, u, res);
            if (!t) res += m;
            else if (t == 1) res++;

            ans += t;
        }
    }

    return ans;
}

int main() {
    scanf("%d%d", &n, &m);
    memset(h, -1, sizeof h);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b), add(b, a);
    }

    bfs();
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        int p = lca(a, b);
        d[a]++, d[b]++, d[p] -= 2;
    }
    
    int res = 0;
    dfs(1, -1, res);
    printf("%d\n", res);

    return 0;
}