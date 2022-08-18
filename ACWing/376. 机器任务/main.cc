#include <iostream>
#include <cstring>
using namespace std;

const int N = 110;
int n, m, k;
bool g[N][N], st[N];
int match[N];

bool dfs(int u) {
    for (int i = 1; i <= m; i++)
        if (!st[i] && g[u][i]) {
            st[i] = true;
            if (!match[i] || dfs(match[i])) {
                match[i] = u;
                return true;
            }
        }

    return false;
}

int main() {
    while (cin >> n, n) {
        cin >> m >> k;
        memset(g, 0, sizeof g);
        memset(match, 0, sizeof match);

        while (k--) {
            int t, a, b;
            cin >> t >> a >> b;
            if (!a || !b) continue;
            g[a][b] = true;
        }

        int res = 0;
        for (int i = 1; i <= n; i++) {
            memset(st, 0, sizeof st);
            if (dfs(i)) res++;
        }
        
        cout << res << endl;
    }
    
    return 0;
}