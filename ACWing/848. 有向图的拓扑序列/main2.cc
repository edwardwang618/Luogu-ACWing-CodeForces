#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int N = 100010;
int n, m;
int h[N], e[N], ne[N], idx;
int vis[N];
int res[N], cnt;

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

bool dfs(int u) {
    vis[u] = 0;
    for (int i = h[u]; i != -1; i = ne[i]) {
        int j = e[i];
        if (vis[j] == -1 && !dfs(j)) return false;
        else if (!vis[j]) return false;
    }
    
    vis[u] = 1;
    res[++cnt] = u;
    return true;
}

int main() {
    memset(h, -1, sizeof h);
    cin >> n >> m;
    while (m--) {
        int a, b;
        cin >> a >> b;
        add(a, b);
    }

    memset(vis, -1, sizeof vis);
    for (int i = 1; i <= n; i++)
        if (vis[i] == -1 && !dfs(i)) {
            puts("-1");
            return 0;
        }

    for (int i = n; i; i--) cout << res[i] << ' ';
    return 0;
}