#include <iostream>
#include <cstring>
using namespace std;

const int N = 110, M = 10010;
int n, m;
int h[N], e[M], ne[M], idx;
int dfn[N], low[N], timestamp;
int stk[N], top;
bool in_stk[N];
int id[N], scc_cnt;
int din[N], dout[N];

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void tarjan(int u) {
    dfn[u] = low[u] = ++timestamp;
    stk[top++] = u, in_stk[u] = true;
    for (int i = h[u]; ~i; i = ne[i]) {
        int j = e[i];
        if (!dfn[j]) {
            tarjan(j);
            low[u] = min(low[u], low[j]);
        } else if (in_stk[j]) low[u] = min(low[u], dfn[j]);
    }

    if (dfn[u] == low[u]) {
        ++scc_cnt;
        int y;
        do {
            y = stk[--top];
            in_stk[y] = false;
            id[y] = scc_cnt;
        } while (y != u);
    }
}

int main() {
    scanf("%d", &n);
    memset(h, -1, sizeof h);
    for (int i = 1; i <= n; i++) {
        int t;
        while (cin >> t, t) add(i, t);
    }

    for (int i = 1; i <= n; i++) 
        if (!dfn[i])
            tarjan(i);

    for (int i = 1; i <= n; i++) 
        for (int j = h[i]; ~j; j = ne[j]) {
            int k = e[j];
            int a = id[i], b = id[k];
            if (a != b) {
                dout[a]++;
                din[b]++;
            }
        }

    int a = 0, b = 0;
    for (int i = 1; i <= scc_cnt; i++) {
        if (!din[i]) a++;
        if (!dout[i]) b++;
    }

    printf("%d\n", a);
    if (scc_cnt == 1) printf("0\n");
    else printf("%d\n", max(a, b));

    return 0;
}