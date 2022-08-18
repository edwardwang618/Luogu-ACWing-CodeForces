#include <iostream>
#include <cstring>
using namespace std;

const int N = 110, INF = 0x3f3f3f3f;
int n, m;
int g[N][N], level[N];
int dist[N];
bool st[N];

int dijkstra(int l, int r) {
    memset(dist, 0x3f, sizeof dist);
    memset(st, 0, sizeof st);
    dist[0] = 0;

    for (int i = 0; i < n + 1; i++) {
        int t = -1;
        for (int j = 0; j <= n; j++)
            if (!st[j] && (j == 0 || (l <= level[j] && level[j] <= r)) && (t == -1 || dist[t] > dist[j]))
                t = j;
    
        st[t] = true;
        for (int j = 1; j <= n; j++)
            if (!st[j] && l <= level[j] && level[j] <= r)
                dist[j] = min(dist[j], dist[t] + g[t][j]);
    }

    return dist[1];
}

int main() {
    cin >> m >> n;

    memset(g, 0x3f, sizeof g);

    for (int i = 1; i <= n; i++) {
        int price, cnt;
        cin >> price >> level[i] >> cnt;
        g[0][i] = min(g[0][i], price);
        for (int j = 0; j < cnt; j++) {
            int id, cost;
            cin >> id >> cost;
            g[id][i] = min(g[id][i], cost);
        }
    }

    int res = INF;
    for (int i = level[1] - m; i <= level[1]; i++)
        res = min(res, dijkstra(i, i + m));
    
    cout << res << endl;

    return 0;
}