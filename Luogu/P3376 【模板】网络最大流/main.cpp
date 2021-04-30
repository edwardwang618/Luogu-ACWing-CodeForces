#include <iostream>
#include <cstring>
using namespace std;

const int N = 210, M = 10050;
const long INF = 1e8;
int n, m, S, T;
int h[N], e[M], ne[M], idx;
long f[M];
int q[N], d[N], cur[N];

void add(int a, int b, long c) {
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

long dfs(int u, long limit) {
    if (u == T) return limit;

    long flow = 0;
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

long dinic() {
    long r = 0, flow;
    while (bfs()) while (flow = dfs(S, INF)) r += flow;
    return r;
}

int main() {
    scanf("%d%d%d%d", &n, &m, &S, &T);

    memset(h, -1, sizeof h);
    for (int i = 0; i < m; i++) {
        int a, b; 
        long c;
        scanf("%d%d%ld", &a, &b, &c);
        add(a, b, c);
    }

    printf("%ld\n", dinic());

    return 0;
}