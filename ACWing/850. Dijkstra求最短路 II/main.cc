#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

typedef pair<int, int> PII;

const int N = 150010;
int n, m;
int h[N], e[N], w[N], ne[N], idx;
int dist[N];
bool st[N];

void add(int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

int dijkstra() {
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;

    priority_queue<PII, vector<PII>, greater<PII> > heap;
    heap.push({0, 1});

    while (!heap.empty()) {
        auto t = heap.top();
        heap.pop();

        int v = t.second, dis = t.first;
        if (st[v]) continue;

        if (v == n) break;
        
        st[v] = true;
        for (int i = h[v]; i != -1; i = ne[i]) {
            int j = e[i];
            if (!st[j] && dist[j] > dis + w[i]) {
                dist[j] = dis + w[i];
                heap.push({dist[j], j});
            }
        }
    }

    return dist[n] == 0x3f3f3f3f ? -1 : dist[n];
}

int main() {
    cin >> n >> m;

    memset(h, -1, sizeof h);

    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }

    cout << dijkstra() << endl;

    return 0;
}