#include <iostream>
#include <cstring>
using namespace std;

const int N = 210;
int n, m;
bool g[N][N];
int match[N];
bool st[N];

bool dfs(int u) {
    for (int i = 1; i <= m; i++) {
        if (st[i]) continue;
        if (!g[u][i]) continue;

        st[i] = true;
        if (!match[i] || dfs(match[i])) {
            match[i] = u;
            return true;
        }
    }

    return false;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        while (k--) {
            int j;
            cin >> j;
            g[i][j] = true;
        }
    }

    int res = 0;
    for (int i = 1; i <= n; i++) {
        memset(st, 0, sizeof st);
        if (dfs(i)) res++;
    }

    cout << res << endl;

    return 0;
}