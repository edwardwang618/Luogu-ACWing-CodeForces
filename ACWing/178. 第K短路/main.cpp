#include <iostream>
#include <cstring>
#include <queue>

#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;
typedef pair<int, PII> PIII;

const int N = 1010, M = 2 * 100000 + 10;
int n, m, S, T, K;
int h[N], rh[N], e[M], w[M], ne[M], idx;
int dist[N];
bool st[N];

void add(int h[], int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void dijkstra() {
    memset(dist, 0x3f, sizeof dist);
    priority_queue<PII, vector<PII>, greater<PII> > heap;
    heap.push({0, T});
    dist[T] = 0;

    while (!heap.empty()) {
        auto t = heap.top();
        heap.pop();

        int v = t.y;
        if (st[v]) continue;
        st[v] = true;

        for (int i = rh[v]; ~i; i = ne[i]) {
            int j = e[i];
            if (dist[j] > dist[v] + w[i]) {
                dist[j] = dist[v] + w[i];
                heap.push({dist[j], j});
            }
        }
    }
}

int astar() {
    priority_queue<PIII, vector<PIII>, greater<PIII> > heap;
    heap.push({dist[S], {0, S}});

    int cnt = 0;
    while (!heap.empty()) {
        auto t = heap.top();
        heap.pop();

        int v = t.y.y, dis = t.y.x;
        if (v == T) cnt++;
        if (cnt == K) return dis;

        for (int i = h[v]; ~i; i = ne[i]) {
            int j = e[i];
            heap.push({dis + w[i] + dist[j], {dis + w[i], j}});
        }
    }

    return -1;
}

int main() {
    scanf("%d%d", &n, &m);
    memset(h, -1, sizeof h);
    memset(rh, -1, sizeof rh);

    for (int i = 0; i < m; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(h, a, b, c), add(rh, b, a, c);
    }

    scanf("%d%d%d", &S, &T, &K);
    if (S == T) K++;

    dijkstra();

    if (dist[S] == 0x3f3f3f3f) printf("-1\n");
    else printf("%d\n", astar());

    return 0;
}