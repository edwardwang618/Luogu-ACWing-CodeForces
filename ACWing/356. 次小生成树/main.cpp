#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1e5 + 10, M = 6e5 + 10, INF = 0x3f3f3f3f;
int n, m;
struct Edge {
    int a, b, w;
    bool flag;
    bool operator<(const Edge & e) const {
        return w < e.w;
    }
} edge[M];
int p[N];
int h[N], e[M], ne[M], w[M], idx;
int depth[N], fa[N][20], d1[N][20], d2[N][20];
int q[N];

void add(int a, int b, int c) {
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}

int find(int x) {
    if (x != p[x]) p[x] = find(p[x]);
    return p[x];
}

long kruskal() {
    for (int i = 1; i <= n; i++) p[i] = i;
    sort(edge, edge + m);
    long res = 0;
    for (int i = 0; i < m; i++) {
        int pa = find(edge[i].a), pb = find(edge[i].b), w = edge[i].w;
        if (pa != pb) {
            p[pa] = pb;
            res += w;
            edge[i].flag = true;
        }
    }

    return res;
}

void build() {
    memset(h, -1, sizeof h);
    for (int i = 0; i < m; i++) 
        if (edge[i].flag) {
            int a = edge[i].a, b = edge[i].b, w = edge[i].w;
            add(a, b, w), add(b, a, w);
        }
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
                q[tt++] = j;

                fa[j][0] = t;
                d1[j][0] = w[i], d2[j][0] = -INF;
                for (int k = 1; k < 17; k++) {
                    int anc = fa[j][k - 1];
                    fa[j][k] = fa[anc][k - 1];
                    int distance[4] = {d1[j][k - 1], d2[j][k - 1], d1[anc][k - 1], d2[anc][k - 1]};
                    d1[j][k] = d2[j][k] = -INF;
                    for (int u = 0; u < 4; u++) {
                        int d = distance[u];
                        if (d > d1[j][k]) d2[j][k] = d1[j][k], d1[j][k] = d;
                        else if (d1[j][k] > d && d > d2[j][k]) d2[j][k] = d;
                    }
                }
            }
        }
    }
}

void update(int& dist1, int& dist2, int d) {
    if (d > dist1) dist2 = dist1, dist1 = d;
    else if (d < dist1 && d > dist2) dist2 = d;
}

int lca(int a, int b, int w) {
    int distance[N * 2];
    int cnt = 0;
    if (depth[a] < depth[b]) swap(a, b);

    int dist1 = -INF, dist2 = -INF;
    for (int k = 16; k >= 0; k--)
        if (depth[fa[a][k]] >= depth[b]) {
            update(dist1, dist2, d1[a][k]);
            update(dist1, dist2, d2[a][k]);
            a = fa[a][k];
        }

    if (a != b) {
        for (int k = 16; k >= 0; k--)
            if (fa[a][k] != fa[b][k]) {
                update(dist1, dist2, d1[a][k]);
                update(dist1, dist2, d2[a][k]);
                update(dist1, dist2, d1[b][k]);
                update(dist1, dist2, d2[b][k]);
                a = fa[a][k], b = fa[b][k];
            }
        
        update(dist1, dist2, d1[a][0]);
        update(dist1, dist2, d1[b][0]);
    }

    if (w > dist1) return w - dist1;
    else if (w > dist2) return w - dist2;
    else return INF;
}

int main() {
    cin >> n >> m;
    memset(h, -1, sizeof h);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edge[i] = {a, b, c};
    }

    long sum = kruskal();
    build();
    bfs();

    long res = 1e18;
    for (int i = 0; i < m; i++) 
        if (!edge[i].flag) {
            int a = edge[i].a, b = edge[i].b, w = edge[i].w;
            res = min(res, sum + lca(a, b, w));
        }

    printf("%ld", res);

    return 0;
}