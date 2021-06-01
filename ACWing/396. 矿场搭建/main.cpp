#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

const int N = 1010, M = 510;
int n, m;
int h[N], e[M], ne[M], idx;
int dfn[N], low[N], timestamp;
int stk[N], top, dcc_cnt;
vector<int> dcc[N];
bool cut[N];

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void tarjan(int u, int from) {
    if (u == from && h[u] == -1) {
        dcc_cnt++;
        dcc[dcc_cnt].push_back(u);
        return;
    }

    dfn[u] = low[u] = ++timestamp;
    stk[top++] = u;

    int cnt = 0;
    for (int i = h[u]; ~i; i = ne[i]) {
        int v = e[i];
        if (!dfn[v]) {
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] >= dfn[u]) {
                cnt++;
                ++dcc_cnt;
                int y;
                do {
                    y = stk[--top];
                    dcc[dcc_cnt].push_back(y);    
                } while (y != v);
                dcc[dcc_cnt].push_back(u);
            }
        } else low[u] = min(low[u], dfn[v]);
    }

    cut[u] = (u == from && cnt > 1) || (u != from && cnt);
}

int main() {
    int T = 1;
    while (cin >> m, m) {
        for (int i = 0; i <= dcc_cnt; i++) dcc[i].clear();
        idx = n = timestamp = top = dcc_cnt = 0;
        memset(h, -1, sizeof h);
        memset(dfn, 0, sizeof dfn);
        memset(cut, 0, sizeof cut);
        for (int i = 1; i <= m; i++) {
            int a, b;
            cin >> a >> b;
            n = max(n, a), n = max(n, b);
            add(a, b), add(b, a);
        }

        for (int i = 1; i <= n; i++) 
            if (!dfn[i]) 
                tarjan(i, i);

        int res = 0;
        unsigned long long num = 1;
        for (int i = 1; i <= dcc_cnt; i++) {
            int cnt = 0, sz = dcc[i].size();
            for (int j = 0; j < sz; j++) 
                if (cut[dcc[i][j]])
                    cnt++;

            if (!cnt) {
                if (sz > 1) res += 2, num *= sz * (sz - 1) / 2;
                else res++;
            } else if (cnt == 1) res++, num *= sz - 1;
        }

        printf("Case %d: %d %llu\n", T++, res, num);
    }

    return 0;
}