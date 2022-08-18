#include <iostream>
#include <cstring>
using namespace std;

const int N = 210, M = 30010;
int n, m;
bool g[N][N], st[N];
int match[N];

bool dfs(int u) {
    for (int i = 1; i <= n; i++) {
        if (st[i] || !g[u][i]) continue;
        st[i] = true;
        if (!match[i] || dfs(match[i])) {
            match[i] = u;
            return true;
        }
    }

    return false;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        g[a][b] = true;
    }
    
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                g[i][j] |= g[i][k] && g[k][j];

    int res = 0;
    for (int i = 1; i <= n; i++) {
        memset(st, 0, sizeof st);
        if (dfs(i)) res++;
    }

    cout << n - res << endl;

    return 0;
}