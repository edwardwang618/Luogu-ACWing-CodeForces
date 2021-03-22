#include <iostream>
using namespace std;

const int N = 510, M = 1050;
int n, m;
int g[N][N];
int res[M], cnt;
int d[N];

void dfs(int u) {
    for (int i = 1; i <= n; i++)
        if (g[u][i]) {
            g[u][i]--, g[i][u]--;
            dfs(i);
        }

    res[++cnt] = u;
}

int main() {
    cin >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a][b]++, g[b][a]++;
        d[a]++, d[b]++;
        n = max(n, max(a, b));
    }

    int s = 1;
    while (!d[s]) s++;
    for (int i = 1; i <= n; i++) 
        if (d[i] % 2) {
            s = i;
            break;
        }

    dfs(s);

    for (int i = cnt; i; i--) cout << res[i] << endl;

    return 0;
}