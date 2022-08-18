#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int N = 100010, M = 400010, mod = 100003;
int n, m;
int h[N], e[M], ne[M], idx;
int dist[N], cnt[N];

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void bfs() {
    memset(dist, -1, sizeof dist);
    dist[1] = 0;
    cnt[1] = 1;

    queue<int> q;
    q.push(1);

    while (q.size()) {
        int t = q.front();
        q.pop();

        for (int i = h[t]; ~i; i = ne[i]) {
            int j = e[i];
            if (dist[j] == -1 || dist[j] == dist[t] + 1) {
                cnt[j] = (cnt[j] + cnt[t]) % mod;
                if (dist[j] == -1) {
                    q.push(j);
                    dist[j] = dist[t] + 1;
                }
            }
        }
    }
}

int main() {
    cin >> n >> m;

    memset(h, -1, sizeof h);
    while (m--) {
        int a, b;
        cin >> a >> b;
        add(a, b), add(b, a);
    }

    bfs();

    for (int i = 1; i <= n; i++) 
        printf("%d\n", cnt[i]);

    return 0;
}