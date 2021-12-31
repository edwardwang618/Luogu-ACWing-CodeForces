#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
using PII = pair<int, int>;

const int N = 1010, M = 2e5 + 10;
int n, m, X;
int h[2][N], e[M], ne[M], w[M], idx;
int dist[2][N];
bool vis[N];

void add(int h[], int a, int b, int c) {
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}

void dijkstra(int hi, int di) {
    memset(vis, 0, sizeof vis);
    dist[di][X] = 0;
    priority_queue<PII, vector<PII>, greater<>> heap;
    heap.push({0, X});
    while (heap.size()) {
        auto t = heap.top(); heap.pop();
        int v = t.second;
        if (vis[v]) continue;
        vis[v] = true;
        for (int i = h[hi][v]; ~i; i = ne[i]) {
            int j = e[i];
            if (!vis[j] && dist[di][j] > dist[di][v] + w[i]) {
                dist[di][j] = dist[di][v] + w[i];
                heap.push({dist[di][j], j});
            }
        }
    }
}

int main() {
    scanf("%d%d%d", &n, &m, &X);
    memset(h, -1, sizeof h);
    while (m--) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(h[0], a, b, c), add(h[1], b, a, c);
    }

    memset(dist, 0x3f, sizeof dist);
    dijkstra(0, 0);
    dijkstra(1, 1);

    int res = 0;
    for (int i = 1; i <= n; i++)
        res = max(res, dist[0][i] + dist[1][i]);

    printf("%d\n", res);

    return 0;
}