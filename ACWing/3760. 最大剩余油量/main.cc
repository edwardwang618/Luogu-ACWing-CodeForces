#include <iostream>
#include <cstring>
using namespace std;

const int N = 3e5 + 10, M = 2 * N;
int n;
int oil[N];
int h[N], e[M], w[M], ne[M], idx;
long res;

void add(int a, int b, int c) {
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}

long dfs(int u, int parent) {
    long d1 = 0, d2 = 0;
    for (int i = h[u]; ~i; i = ne[i]) {
        int v = e[i];
        if (v == parent) continue;
        long d = dfs(v, u);
        if (d < w[i]) continue;
        d -= w[i];
        if (d >= d1) d2 = d1, d1 = d;
        else if (d > d2) d2 = d;
    }

    res = max(res, d1 + d2 + oil[u]);
    return d1 + oil[u];
}

int main() {
    scanf("%d", &n);
    memset(h, -1, sizeof h);
    for (int i = 1; i <= n; i++) scanf("%d", &oil[i]);
    for (int i = 0; i < n - 1; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c), add(b, a, c);
    }

    dfs(1, -1);
    printf("%ld\n", res);

    return 0;
}