#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

typedef pair<int, int> PII;

const int N = 2510;
int n, m;
int st, ed, dis[N];
bool vis[N];
int g[N][N];

int dijkstra() {
    priority_queue<PII, vector<PII>, greater<PII> > heap;
    heap.push({0, st});

    memset(dis, 0x3f, sizeof dis);    
    dis[st] = 0;

    while (heap.size()) {
        auto t = heap.top();
        heap.pop();

        int v = t.second, d = t.first;
        if (v == ed) return dis[v];

        vis[v] = true;

        for (int i = 1; i <= n; i++) {
            if (!vis[i] && dis[i] > dis[v] + g[v][i]) {
                dis[i] = dis[v] + g[v][i];
                heap.push({dis[i], i});
            }
        }
    }

    return -1;
}

int main() {
    cin >> n >> m;
    cin >> st >> ed;

    memset(g, 0x3f3f3f3f, sizeof g);

    for (int i = 0; i < m; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        g[a][b] = g[b][a] = min(g[a][b], c);
    }

    cout << dijkstra() << endl;

    return 0;
}