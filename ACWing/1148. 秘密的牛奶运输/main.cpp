#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 510, M = 1e4 + 10;
int n, m;
struct Edge {
    int a, b, w;
    bool flag;

    bool operator<(const Edge &e) const {
        return w < e.w;
    }
} edge[M];
int h[N], e[N * 2], ne[N * 2], w[N * 2], idx;
int dist1[N][N], dist2[N][N];
int p[N];

void add(int a, int b, int c) {
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}

int find(int x) {
    if (x != p[x]) p[x] = find(p[x]);
    return p[x];
}

void dfs(int u, int fa, int max1, int max2, int d1[], int d2[]) {
    d1[u] = max1;
    d2[u] = max2;
    for (int i = h[u]; ~i; i = ne[i]) {
        int j = e[i];
        if (j == fa) continue;

        int t1 = max1, t2 = max2;
        if (w[i] > t1) t2 = t1, t1 = w[i];
        else if (w[i] < t1 && w[i] > t2) t2 = w[i];

        dfs(j, u, t1, t2, d1, d2);
    }
}

int main() {
    memset(h, -1, sizeof h);
    scanf("%d%d", &n, &m);

    for (int i = 0; i < m; i++)
        scanf("%d%d%d", &edge[i].a, &edge[i].b, &edge[i].w);

    sort(edge, edge + m);

    for (int i = 1; i <= n; i++) p[i] = i;

    long sum = 0;
    for (int i = 0; i < m; i++) {
        int a = edge[i].a, b = edge[i].b, w = edge[i].w;
        int pa = find(a), pb = find(b);
        if (pa != pb) {
            p[pa] = pb;
            sum += w;
            edge[i].flag = true;
            add(a, b, w), add(b, a, w);
        }
    }

    for (int i = 1; i <= n; i++) dfs(i, -1, 0, 0, dist1[i], dist2[i]);

    long res = 1e18;
    for (int i = 0; i < m; i++) {
        if (!edge[i].flag) {
            int a = edge[i].a, b = edge[i].b, w = edge[i].w;
            if (w > dist1[a][b]) res = min(res, sum + w - dist1[a][b]);
            else if (dist2[a][b] < w) res = min(res, sum + w - dist2[a][b]);
        }
    }

    printf("%ld\n", res);
    return 0;
}