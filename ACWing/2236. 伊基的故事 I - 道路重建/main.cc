#include <iostream>
#include <cstring>
using namespace std;

const int N = 510, M = 5010 * 2, INF = 1e8;
int n, m, S, T;
int h[N], e[M], ne[M], f[M], idx;
int q[N], d[N], cur[N];
bool vis_s[N], vis_t[N];

void add(int a, int b, int c) {
    e[idx] = b, ne[idx] = h[a], f[idx] = c, h[a] = idx++;
    e[idx] = a, ne[idx] = h[b], f[idx] = 0, h[b] = idx++;
}

bool bfs() {
    memset(d, -1, sizeof d);
    int hh = 0, tt = 0;
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

void dfs2(int u, bool st[], int t) {
    st[u] = true;
    for (int i = h[u]; ~i; i = ne[i]) {
        int j = i ^ t;
        int v = e[i];
        if (f[j] && !st[v])
            dfs2(v, st, t);
    }
}

int main() {
    scanf("%d%d", &n, &m);
    S = 0, T = n - 1;

    memset(h, -1, sizeof h);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c);
    }
    
    dinic();
    dfs2(S, vis_s, 0);
    dfs2(T, vis_t, 1);

    int res = 0;
    for (int i = 0; i < m * 2; i += 2)
        if (!f[i] && vis_s[e[i ^ 1]] && vis_t[e[i]])
            res++;

    printf("%d", res);

    return 0;
}