#include <iostream>
#include <cstring>
using namespace std;

const int N = 1050, M = (20 * N + N + 20) * 2, INF = 1e8;
int n, m, S, T;
int a[N][25], c[N];
int h[N], e[M], ne[M], f[M], idx;
int q[N], d[N], cur[N];

void add(int a, int b, int c) {
    e[idx] = b, ne[idx] = h[a], f[idx] = c, h[a] = idx++;
    e[idx] = a, ne[idx] = h[b], f[idx] = 0, h[b] = idx++; 
}

bool bfs() {
    int hh = 0, tt = 0;
    memset(d, -1, sizeof d);
    q[tt++] = S, d[S] = 0, cur[S] = h[S];
    while (hh < tt) {
        int t = q[hh++];
        for (int i = h[t]; ~i; i = ne[i]) {
            int v = e[i];
            if (d[v] == -1 && f[i]) {
                d[v] = d[t] + 1;
                if (v == T) return true;

                cur[v] = h[v];
                q[tt++] = v;
            }
        }
    }
    
    return false;
}

int dfs(int u, int limit) {
    if (u == T) return limit;
    int flow = 0;
    for (int i = cur[u]; ~i && flow < limit; i = ne[i]) {
        int v = e[i];
        cur[u] = i;
        if (d[v] == d[u] + 1 && f[i]) {
            int t = dfs(v, min(limit - flow, f[i]));
            if (!t) d[v] = -1;
            f[i] -= t, f[i ^ 1] += t, flow += t;
        }
    }

    return flow;
}

int dinic() {
    int r = 0, flow;
    while (bfs()) while (flow = dfs(S, INF)) r += flow;
    return r;
}

bool check(int l, int r) {
    memset(h, -1, sizeof h), idx = 0;

    for (int i = 1; i <= n; i++) add(S, i, 1);
    for (int i = n + 1; i <= m + n + 1; i++) add(i, T, c[i - n]);
    for (int i = 1; i <= n; i++)
        for (int j = l; j <= r; j++)
            add(i, n + a[i][j], 1);

    return dinic() == n;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];

    for (int i = 1; i <= m; i++) cin >> c[i];
    S = 0, T = n + m + 1;

    int res = m;
    for (int l = 0, r = 0; r <= m; r++) {
        while (l <= r && check(l, r)) {
            res = min(res, r - l + 1);
            l++;
        }
    }

    cout << res << endl;

    return 0;
}