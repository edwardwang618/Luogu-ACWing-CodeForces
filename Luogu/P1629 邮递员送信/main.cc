#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
using PII = pair<int, int>;

const int N = 1010, M = 2e5 + 10;
int n, m;
int h[N * 2], e[M], ne[M], w[M], idx;
int dist[N];
bool vis[N];
long res;

void add(int a, int b, int c) {
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}

void dijkstra(int d) {
    memset(vis, 0, sizeof vis);
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    priority_queue<PII, vector<PII>, greater<>> heap;
    heap.push({0, 1 + d});
    while (heap.size()) {
        auto t = heap.top();
        heap.pop();
        int v = t.second;
        if (vis[v - d]) continue;
        vis[v - d] = true;
        for (int i = h[v]; ~i; i = ne[i]) {
            int j = e[i];
            if (!vis[j - d] && dist[j - d] > dist[v - d] + w[i]) {
                dist[j - d] = dist[v - d] + w[i];
                heap.push({dist[j - d], j});
            }
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);
    memset(h, -1, sizeof h);
    for (int i = 1; i <= m; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c), add(b + N, a + N, c);
    }

    dijkstra(0);
    for (int i = 2; i <= n; i++) res += dist[i];

    dijkstra(N);
    for (int i = 2; i <= n; i++) res += dist[i];

    printf("%ld\n", res);

    return 0;
}