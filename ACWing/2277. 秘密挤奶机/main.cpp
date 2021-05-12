#include <iostream>
#include <cstring>
using namespace std;

const int N = 210, M = 80010, INF = 1e8;
int n, m, K, S, T;
int h[N], e[M], f[M], w[M], ne[M], idx;
int q[N], d[N], cur[N];

void add(int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
    e[idx] = a, w[idx] = c, ne[idx] = h[b], h[b] = idx++;
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
        cur[u] = i;
        int v = e[i];
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

bool check(int mid) {
    for (int i = 0; i < idx; i++) 
        if (w[i] > mid) f[i] = 0;
        else f[i] = 1;
        
    return dinic() >= K;
}

int main() {
    scanf("%d%d%d", &n, &m, &K);
    S = 1, T = n;
    memset(h, -1, sizeof h);
    while (m--) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c);
    }

    int l = 1, r = 1e6;
    while (l < r) {
        int mid = l + (r - l >> 1);
        if (check(mid)) r = mid;
        else l = mid + 1;
    }

    printf("%d", l);

    return 0;
}