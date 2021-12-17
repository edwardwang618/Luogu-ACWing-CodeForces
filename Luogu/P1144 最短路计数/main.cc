#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int N = 1e6 + 10, M = 4e6 + 10, MOD = 1e5 + 3;
int n, m;
int h[N], e[M], ne[M], idx;
int dist[N], cnt[N];
queue<int> q;

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void bfs() {
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    cnt[1] = 1;
    q.push(1);
    while (q.size()) {
        auto t = q.front(); q.pop();
        for (int i = h[t]; ~i; i = ne[i]) {
            int v = e[i];
            if (dist[v] > dist[t] + 1) {
                dist[v] = dist[t] + 1;
                cnt[v] = cnt[t];
                q.push(v);
            } else if (dist[v] == dist[t] + 1)
                cnt[v] = (cnt[v] + cnt[t]) % MOD;
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);
    memset(h, -1, sizeof h);
    while (m--) {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b), add(b, a);
    }
    
    bfs();
    for (int i = 1; i <= n; i++)
        printf("%d\n", cnt[i]);

    return 0;
}