#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int N = 100010, M = 2000010;
int n, m;
int w[N];
int hs[N], ht[N], e[M], ne[M], idx;
int dmin[N], dmax[N];
bool st[N];

void add(int h[], int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void spfa(int h[], int dist[], int type) {
    queue<int> q;
    if (type == 0) {
        memset(dist, 0x3f, sizeof dmin);
        dist[1] = w[1];
        q.push(1);
    } else {
        dist[n] = w[n];
        q.push(n);
    }

    while (q.size()) {
        int t = q.front();
        q.pop();

        st[t] = false;
        for (int i = h[t]; ~i; i = ne[i]) {
            int j = e[i];
            if (type == 0 && dist[j] > min(dist[t], w[j]) || type == 1 && dist[j] < max(dist[t], w[j])) {
                if (type == 0) dist[j] = min(dist[t], w[j]);
                else dist[j] = max(dist[t], w[j]);

                if (!st[j]) {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &w[i]);

    memset(hs, -1, sizeof hs);
    memset(ht, -1, sizeof ht);

    while (m--) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(hs, a, b), add(ht, b, a);
        if (c == 2) add(hs, b, a), add(ht, a, b);
    }
    
    spfa(hs, dmin, 0);
    spfa(ht, dmax, 1);

    int res = 0;
    for (int i = 1; i <= n; i++)
        res = max(res, dmax[i] - dmin[i]);

    cout << res << endl;

    return 0;
}