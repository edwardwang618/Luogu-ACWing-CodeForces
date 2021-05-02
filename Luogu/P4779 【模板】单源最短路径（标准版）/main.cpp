#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

typedef pair<int, int> PII;

const int N = 1e5 + 10, M = 2e5 + 10;
int n, m, S;
int h[N], e[M], ne[M], w[M], idx;
int dist[N];
bool st[N];

void add(int a, int b, int c) {
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}

void dijkstra(int S) {
    priority_queue<PII, vector<PII>, greater<PII> > heap;
    memset(dist, 0x3f, sizeof dist);
    dist[S] = 0;

    heap.push({0, S});
    while (heap.size()) {
        auto t = heap.top(); heap.pop();
        int v = t.second, d = t.first;
        if (st[v]) continue;

        st[v] = true;
        for (int i = h[v]; ~i; i = ne[i]) {
            int j = e[i];
            if (!st[j] && dist[j] > d + w[i]) {
                dist[j] = d + w[i];
                heap.push({dist[j], j});
            }
        }
    }
}

int main() {
    cin >> n >> m >> S;

    memset(h, -1, sizeof h);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }

    dijkstra(S);

    for (int i = 1; i <= n; i++) cout << dist[i] << ' ';
    cout << endl;

    return 0;
}