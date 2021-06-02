#include <iostream>
#include <cstring>
using namespace std;

const int N = 2010, M = 1000010;
int n, m;
int h[N], e[M], ne[M], w[M], idx;
int q[N];
int d[N];
int dist[N];
bool st[N];

void add(int a, int b, int c) {
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
    d[b]++;
}

void topsort() {
    int hh = 0, tt = 0;
    for (int i = 1; i <= n + m; i++)
        if (!d[i])
            q[tt++] = i;
    
    while (hh < tt) {
        int t = q[hh++];
        for (int i = h[t]; ~i; i = ne[i]) {
            int v = e[i];
            if (--d[v] == 0) q[tt++] = v;
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);
    memset(h, -1, sizeof h);
    for (int i = 1; i <= m; i++) {
        memset(st, 0, sizeof st);
        int cnt;
        scanf("%d", &cnt);
        int start = n, end = 1;
        while (cnt--) {
            int stop;
            scanf("%d", &stop);
            start = min(start, stop);
            end = max(end, stop);
            st[stop] = true;
        }

        int v = n + i;
        for (int j = start; j <= end; j++) 
            if (!st[j]) add(j, v, 0);
            else add(v, j, 1);
    }

    topsort();

    for (int i = 1; i <= n; i++) dist[i] = 1;
    for (int i = 0; i < n + m; i++) {
        int v = q[i];
        for (int j = h[v]; ~j; j = ne[j])
            dist[e[j]] = max(dist[e[j]], dist[v] + w[j]);
    }

    int res = 0;
    for (int i = 1; i <= n; i++) res = max(res, dist[i]);
    printf("%d\n", res);

    return 0;
}