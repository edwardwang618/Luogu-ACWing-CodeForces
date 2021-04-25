#include <iostream>
#include <cstring>
using namespace std;

const int N = 5010, M = 2e5 + 10, INF = 0x3f3f3f3f;
int n, m;
int g[N][N], dist[N];
bool st[N];

int prim() {
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;

    int res = 0;
    for (int i = 1; i <= n; i++) {
        int t = -1;
        for (int j = 1; j <= n; j++)
            if (!st[j] && (t == -1 || dist[j] < dist[t]))
                t = j;
        
        if (dist[t] == INF) return -1;
        
        st[t] = true;
        res += dist[t];
        
        for (int j = 1; j <= n; j++)
            if (!st[j] && dist[j] > g[t][j])
                dist[j] = g[t][j];
    }

    return res;
}

int main() {
    cin >> n >> m;

    memset(g, 0x3f, sizeof g);
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a][b] = g[b][a] = min(g[a][b], c);
    }

    int res = prim();
    if (res == -1) cout << "orz" << endl;
    else cout << res << endl;

    return 0;
}