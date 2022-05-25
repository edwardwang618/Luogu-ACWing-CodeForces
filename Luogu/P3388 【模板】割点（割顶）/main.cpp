#include <iostream>
#include <cstring>
using namespace std;

const int N = 2e4 + 10, M = 2e5 + 10;
int n, m;
int h[N], e[M], ne[M], idx;
int dfn[N], low[N], timestamp;
bool cut[N];
int tot;

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void tarjan(int u, int from) {
    dfn[u] = low[u] = ++timestamp;
    int child = 0;
    for (int i = h[u]; ~i; i = ne[i]) {
        int v = e[i];
        if (!dfn[v]) {
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] >= dfn[u]) child++;
        } else if (v != from) low[u] = min(low[u], dfn[v]);
    }

    if (u == from && child >= 2 || u != from && child) {
        cut[u] = true;
        tot++;
    }
}

int main() {
    scanf("%d%d", &n, &m);
    memset(h, -1, sizeof h);
    while (m--) {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b), add(b, a);
    }
    
    for (int i = 1; i <= n; i++)
        if (!dfn[i])
            tarjan(i, i);

    printf("%d\n", tot);

    for (int i = 1; i <= n; i++)
        if (cut[i])
            printf("%d ", i);
}