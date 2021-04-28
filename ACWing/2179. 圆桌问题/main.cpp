#include <iostream>
#include <cstring>
using namespace std;

const int N = 430, M = (150 * 270 + N) * 2, INF = 1e8;
int n, m, S, T;
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

int main() {
    scanf("%d%d", &m, &n);
    S = 0, T = m + n + 1;
    memset(h, -1, sizeof h);

    int tot = 0;
    for (int i = 1; i <= m; i++) {
        int c;
        scanf("%d", &c);
        add(S, i, c);
        tot += c;
    }

    for (int i = 1; i <= n; i++) {
        int c;
        scanf("%d", &c);
        add(m + i, T, c);
    }

    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            add(i, m + j, 1);

    if (dinic() != tot) printf("0\n");
    else {
        printf("1\n");
        for (int i = 1; i <= m; i++) {
            for (int j = h[i]; ~j; j = ne[j]) 
                if (e[j] > m && e[j] <= m + n && !f[j]) 
                    printf("%d ", e[j] - m);
            printf("\n");
        }
    }

    return 0;
}