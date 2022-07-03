#include <iostream>
#include <cstring>
using namespace std;

const int N = 210;
int n, m;
bool forb[N][N];
int match[N];
bool st[N];

bool dfs(int u) {
    for (int i = 1; i <= m; i++)
        if (!st[i] && !forb[u][i]) {
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
    int k;
    cin >> k;
    while (k--) {
        int a, b;
        cin >> a >> b;
        forb[a][b] = true;
    }
    
    int res = 0;
    for (int i = 1; i <= n; i++) {
        memset(st, 0, sizeof st);
        if (dfs(i)) res++;
    }

    cout << res << endl;

    return 0;
}