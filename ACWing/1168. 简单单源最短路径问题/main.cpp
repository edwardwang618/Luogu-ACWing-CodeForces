#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int N = 1010, M = 1e5 + 10, INF = 0x3f3f3f3f3f3f3f3f;
int n, m, S;
int h[N], e[M], ne[M], w[M], idx;
long dist[N];
int cnt[N];
bool st[N];

void add(int a, int b, int c) {
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}

bool spfa() {
    memset(dist, 0x3f, sizeof dist);
    dist[S] = 0;

    queue<int> q;
    for (int i = 1; i <= n; i++) {
        q.push(i);
        st[i] = true;
    }

    while (q.size()) {
        int t = q.front(); q.pop();
        st[t] = false;

        for (int i = h[t]; ~i; i = ne[i]) {
            int v = e[i];
            if (dist[v] > dist[t] + w[i]) {
                dist[v] = dist[t] + w[i];
                cnt[v] = cnt[t] + 1;
                if (cnt[v] >= n) return true;

                if (!st[v]) {
                    q.push(v);
                    st[v] = false;
                }
            }
        }
    }
    
    return false;
}

int main() {
    cin >> n >> m >> S;

    memset(h, -1, sizeof h);
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }
    
    if (spfa()) cout << -1 << endl;
    else {
        for (int i = 1; i <= n; i++)
            if (dist[i] < INF) cout << dist[i] << endl;
            else cout << "NoPath" << endl;
    }

    return 0;
}