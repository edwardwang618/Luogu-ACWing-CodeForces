#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

typedef pair<int, int> PII;

const int N = 2010, INF = 0x3f3f3f3f;
int n, m;
int g[N][N];
int dist[N], cnt[N];
bool st[N];

void dijkstra(int s) {
    memset(dist, 0x3f, sizeof dist);
    priority_queue<PII, vector<PII>, greater<PII> > heap;
    heap.push({0, s});

    dist[s] = 0;
    cnt[s] = 1;

    while (heap.size()) {
        auto t = heap.top();
        heap.pop();
        int v = t.second, d = t.first;

        if (st[v]) continue;
        st[v] = true;

        for (int i = 1; i <= n; i++) {
            if (g[v][i] == INF) continue;

            if (dist[i] > d + g[v][i]) {
                dist[i] = d + g[v][i];
                cnt[i] = cnt[v];
                heap.push({dist[i], i});
            } else if (dist[i] == d + g[v][i]) {
                cnt[i] += cnt[v];
            }
        }
    }
}

int main() {
    cin >> n >> m;
    memset(g, 0x3f, sizeof g);
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a][b] = min(g[a][b], c);
    }

    dijkstra(1);

    if (dist[n] == INF) printf("No answer\n");
    else printf("%d %d\n", dist[n], cnt[n]);

    return 0;
}