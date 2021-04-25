#include <iostream>
#include <cstring>
using namespace std;

const int N = 510, M = 5e4 + 10;
int n1, n2, m;
bool g[N][N];
int match[N];
bool st[N];

bool dfs(int u) {
    for (int i = 1; i <= n2; i++) {
        if (!g[u][i]) continue;
        if (st[i]) continue;

        st[i] = true;
        if (!match[i] || dfs(match[i])) {
            match[i] = u;
            return true;
        }
    }

    return false;
}

int main() {
    scanf("%d%d%d", &n1, &n2, &m);

    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        g[a][b] = true;
    }
    
    int res = 0;
    for (int i = 1; i <= n1; i++) {
        memset(st, 0, sizeof st);
        if (dfs(i)) res++;
    }

    printf("%d\n", res);

    return 0;
}