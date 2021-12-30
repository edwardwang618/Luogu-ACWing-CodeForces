#include <iostream>
using namespace std;

const int N = 1e6 + 10;
int n;
int h[N], e[N], ne[N], idx;
int res;

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void dfs(int u, int depth) {
    if (!u) {
        res = max(res, depth);
        return;
    }

    for (int i = h[u]; ~i; i = ne[i])
        dfs(e[i], depth + 1);
}

int main() {
    scanf("%d", &n);
    memset(h, -1, sizeof h);
    for (int i = 1; i <= n; i++) {
        int l, r;
        scanf("%d%d", &l, &r);
        add(i, l), add(i, r);
    }

    dfs(1, 0);
    printf("%d\n", res);

    return 0;
}