#include <iostream>
#include <cstring>
using namespace std;

const int N = 10010, M = 200010, INF = 1e8;
int n, m, S, T;
int h[N], e[M], f[M], ne[M], idx;
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
        cur[u] = i;
        int v = e[i];
        if (d[v] == d[u] + 1 && f[i]) {
            int t = dfs(v, min(f[i], limit - flow));
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

int main() {
    scanf("%d%d%d%d", &n, &m, &S, &T);
    memset(h, -1, sizeof h);
    while (m--) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c);
    }
    
    printf("%d\n", dinic());

    return 0;
}