#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 50, M = 4010;
int n, m, deg[N];
int h[N], e[M], ne[M], no[M], idx;
bool vis[M];
struct Edge {
    int x, y, idd;
} ed[M];
int sz, res[M];

void add(int a, int b, int i) {
    e[idx] = b, ne[idx] = h[a], no[idx] = i, h[a] = idx++;
}

bool cmp(Edge e1, Edge e2) { return e1.idd > e2.idd; }

void dfs(int u) {
    while (h[u] != -1) {
        if (vis[h[u]]) {
            h[u] = ne[h[u]];
            continue;
        }
        
        vis[h[u] ^ 1] = true;
        int j = e[h[u]], x = h[u];
        h[u] = ne[h[u]];
        dfs(j);
        res[sz++] = no[x];
    }
}

int main() {
    while (1) {
        memset(deg, 0, sizeof deg);
        memset(h, -1, sizeof h);
        memset(no, 0, sizeof no);
        memset(vis, 0, sizeof vis);
        idx = 0, sz = 0;

        int a, b, i, john;
        n = 0;

        for (m = 1;; m++) {
            scanf("%d%d", &a, &b);
            if (!a && !b) break;

            if (m == 1) john = min(a, b);
            n = max(n, max(a, b));

            scanf("%d", &i);
            ed[m] = {a, b, i};
            deg[a]++, deg[b]++;
        }

        m--;
        if (!m) break;

        bool success = true;
        for (int i = 1; i <= n; i++)
            if (deg[i] & 1) {
                success = false;
                break;
            }

        if (!success) {
            puts("Round trip does not exist.");
            continue;
        }

        sort(ed + 1, ed + m + 1, cmp);
        for (int i = 1; i <= m; i++) {
            int x = ed[i].x, y = ed[i].y, idd = ed[i].idd;
            add(x, y, idd), add(y, x, idd);
        }

        dfs(john);
        for (int i = sz - 1; i >= 0; i--) printf("%d ", res[i]);
        printf("\n");
    }

    return 0;
}