#include <iostream>
#include <cstring>
using namespace std;

const int N = 10010, M = 20010;
int n, m;
int h[N], e[M], ne[M], idx;
int q[N];
int d[N];
int dist[N];

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

bool topsort() {
    int hh = 0, tt = 0;
    for (int i = 1; i <= n; i++) 
        if (!d[i])
            q[tt++] = i;

    while (hh < tt) {
        int t = q[hh++];
        for (int i = h[t]; ~i; i = ne[i]) {
            int v = e[i];
            if (--d[v] == 0) q[tt++] = v;
        }
    }

    return tt == n;
}

int main() {
    scanf("%d%d", &n, &m);
    memset(h, -1, sizeof h);
    while (m--) {
        int a, b;
        scanf("%d%d", &a, &b);
        add(b, a);
        d[a]++;
    }

    if (!topsort()) puts("Poor Xed");
    else {
        for (int i = 1; i <= n; i++) dist[i] = 100;
        for (int i = 0; i < n; i++) {
            int v = q[i];
            for (int j = h[v]; ~j; j = ne[j])
                dist[e[j]] = max(dist[e[j]], dist[v] + 1);
        }

        int res = 0;
        for (int i = 1; i <= n; i++) res += dist[i];
        printf("%d\n", res);
    }

    return 0;
}