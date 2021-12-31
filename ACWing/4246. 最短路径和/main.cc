#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
using PII = pair<int, int>;

const int N = 1e6 + 10, M = 2 * N;
int n, m;
int h[N], rh[N], e[M], ne[M], w[M], idx;
int dist[N];
bool vis[N];

void add(int h[], int a, int b, int c) {
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}

long dijkstra(int h[]) {
    memset(dist, 0x3f, sizeof dist);
    memset(vis, 0, sizeof vis);

    long res = 0;
    priority_queue<PII, vector<PII>, greater<>> heap;
    dist[1] = 0;
    heap.push({0, 1});
    while (heap.size()) {
        auto t = heap.top(); heap.pop();
        int v = t.second;
        if (vis[v]) continue;
        vis[v] = true;
        res += dist[v];

        for (int i = h[v]; ~i; i = ne[i]) {
            int j = e[i];
            if (!vis[j] && dist[j] > dist[v] + w[i]) {
                dist[j] = dist[v] + w[i];
                heap.push({dist[j], j});
            }
        }
    }
    
    return res;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        memset(h, -1, sizeof h);
        memset(rh, -1, sizeof rh);
        idx = 0;
        scanf("%d%d", &n, &m);
        while (m--) {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            add(h, a, b, c), add(rh, b, a, c);
        }

        printf("%ld\n", dijkstra(h) + dijkstra(rh));
    }

    return 0;
}