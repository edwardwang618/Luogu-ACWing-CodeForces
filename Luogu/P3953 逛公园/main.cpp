#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

typedef pair<int, int> PII;

const int N = 100010, M = 200010;
int n, m, K, P;
int h[N], e[M], ne[M], w[M], idx;
int dist[N], cnt[50][N];
bool st[N];

void add(int a, int b, int c) {
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}

void dijkstra() {
    memset(dist, 0x3f, sizeof dist);
    memset(st, 0, sizeof st);
    priority_queue<PII, vector<PII>, greater<PII> > heap;
    heap.push({0, 1});
    dist[1] = 0;

    while (heap.size()) {
        auto t = heap.top();
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
    int T;
    cin >> T;
    while (T--) {
        memset(h, -1, sizeof h);
        cin >> n >> m >> K >> P;
        while (m--) {
            int a, b, c;
            cin >> a >> b >> c;
            add(a, b, c);
        }

        dijkstra();

    }
    



    return 0;
}