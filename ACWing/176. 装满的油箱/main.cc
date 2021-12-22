#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

struct Ver {
    int d, u, c;
    bool operator<(const Ver &v) const {
        return d > v.d;
    }
};
const int N = 1010, M = 20010, C = 1010;
int n, m;
int h[N], e[M], ne[M], w[M], idx;
int price[N];
int dist[N][C];
bool vis[N][C];

void add(int a, int b, int c) {
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}

int dijkstra(int c, int start, int end) {
    memset(dist, 0x3f, sizeof dist);
    memset(vis, 0, sizeof vis);
    priority_queue<Ver> heap;
    heap.push({0, start, 0});
    while (heap.size()) {
        auto t = heap.top(); heap.pop();
        if (t.u == end) return t.d;
        if (vis[t.u][t.c]) continue;
        vis[t.u][t.c] = true;
        if (t.c < c) {
            if (dist[t.u][t.c + 1] > t.d + price[t.u]) {
                dist[t.u][t.c + 1] = t.d + price[t.u];
                heap.push({dist[t.u][t.c + 1], t.u, t.c + 1});
            }
        } 
        for (int i = h[t.u]; ~i; i = ne[i]) {
            int j = e[i];
            if (t.c >= w[i]) {
                if (dist[j][t.c - w[i]] > t.d) {
                    dist[j][t.c - w[i]] = t.d;
                    heap.push({dist[j][t.c - w[i]], j, t.c - w[i]});
                }
            }
        }
    }

    return -1;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%d", &price[i]);
    memset(h, -1, sizeof h);
    while (m--) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c), add(b, a, c);
    }

    int query;
    scanf("%d", &query);
    while (query--) {
        int c, s, e;
        scanf("%d%d%d", &c, &s, &e);
        int t = dijkstra(c, s, e);
        if (~t) printf("%d\n", t);
        else puts("impossible");
    }

    return 0;
}