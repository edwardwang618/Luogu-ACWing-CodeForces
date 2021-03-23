#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int N = 810, M = 3000, INF = 0x3f3f3f3f;
int n, p, m;
int id[N];
int h[N], e[M], ne[M], w[M], idx;
int dist[N], q[N];
bool st[N];

void add(int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

int spfa(int u) {
    memset(st, 0, sizeof st);
    memset(dist, 0x3f, sizeof dist);
    dist[u] = 0;

    queue<int> q;
    q.push(u);
    while (q.size()) {
        int t = q.front();
        q.pop();
        st[t] = false;

        for (int i = h[t]; ~i; i = ne[i]) {
            int j = e[i];
            if (dist[j] > dist[t] + w[i]) {
                dist[j] = dist[t] + w[i];
                if (!st[j]) {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }

    int res = 0;
    for (int i = 0; i < n; i++) {
        int j = id[i];
        if (dist[j] == INF) return INF;
        res += dist[j];
    }

    return res;
}

int main() {
    cin >> n >> p >> m;
    for (int i = 0; i < n; i++) cin >> id[i];

    memset(h, -1, sizeof h);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c), add(b, a, c);
    }

    int res = INF;
    for (int i = 1; i <= p; i++) res = min(res, spfa(i));

    cout << res << endl;

    return 0;
}