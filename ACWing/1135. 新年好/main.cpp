#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

typedef pair<int, int> PII;

const int N = 50010, M = 200010, INF = 0x3f3f3f3f;
int n, m;
int source[6];
int h[N], e[M], ne[M], w[M], idx;
int dist[6][N];
bool st[N];

void add(int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void dijkstra(int start, int dis[]) {
    memset(st, 0, sizeof st);
    priority_queue<PII, vector<PII>, greater<PII> > heap;
    heap.push({0, start});
    dis[start] = 0;

    while (heap.size()) {
        auto t = heap.top();
        heap.pop();

        int v = t.second, d = t.first;
        if (st[v]) continue;

        st[v] = true;
        for (int i = h[v]; ~i; i = ne[i]) {
            int j = e[i];
            if (!st[j] && dis[j] > d + w[i]) {
                dis[j] = d + w[i];
                heap.push({dis[j], j});
            }
        }
    }
}

int dfs(int u, int start, int distance) {
    if (u == 6) return distance;

    int res = INF;
    for (int i = 1; i <= 5; i++)
        if (!st[i]) {
            int next = source[i];
            st[i] = true;
            res = min(res, dfs(u + 1, i, distance + dist[start][next]));
            st[i] = false;
        }

    return res;
}

int main() {
    cin >> n >> m;
    source[0] = 1;
    for (int i = 1; i <= 5; i++) cin >> source[i];

    memset(h, -1, sizeof h);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c), add(b, a, c);
    }

    memset(dist, 0x3f, sizeof dist);
    for (int i = 0; i < 6; i++) dijkstra(source[i], dist[i]);

    memset(st, 0, sizeof st);
    printf("%d\n", dfs(1, 0, 0));

    return 0;
}