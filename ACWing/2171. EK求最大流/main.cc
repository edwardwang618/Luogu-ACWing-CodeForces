#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int N = 1010, M = 20010, INF = 1e8;
int n, m, S, T;
int h[N], e[M], f[M], ne[M], idx;
int d[N], pre[N];
bool st[N];

void add(int a, int b, int c) {
    e[idx] = b, f[idx] = c, ne[idx] = h[a], h[a] = idx++;
    e[idx] = a, f[idx] = 0, ne[idx] = h[b], h[b] = idx++;
}

bool bfs() {
    queue<int> q;
    memset(st, 0, sizeof st);

    q.push(S), st[S] = true, d[S] = INF;
    while (q.size()) {
        int t = q.front(); q.pop();
        for (int i = h[t]; ~i; i = ne[i]) {
            int v = e[i];
            if (!st[v] && f[i]) {
                st[v] = true;
                d[v] = min(d[t], f[i]);
                pre[v] = i;
                if (v == T) return true;

                q.push(v);
            }
        }
    }

    return false;
}

int EK() {
    int res = 0;
    while (bfs()) {
        res += d[T];
        for (int i = T; i != S; i = e[pre[i] ^ 1])
            f[pre[i]] -= d[T], f[pre[i] ^ 1] += d[T];
    }
    
    return res;
}

int main() {
    cin >> n >> m >> S >> T;
    memset(h, -1, sizeof h);

    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }
    
    cout << EK() << endl;

    return 0;
}