#include <iostream>
#include <cstring>
using namespace std;

typedef pair<int, int> PII;

const int N = 1e4 + 10, M = 5e5 + 10, INF = (1 << 31) - 1;
int n, m, S;
int h[N], e[M], ne[M], w[M], idx;
int dist[N];
bool st[N];

void add(int a, int b, int c) {
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}

void dijkstra(int S) {
    memset(dist, 0x3f, sizeof dist);
    dist[S] = 0;

    for (int i = 1; i <= n; i++) {
        int t = -1;
        for (int j = 1; j <= n; j++) 
            if (!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;
        
        st[t] = true;
        for (int j = h[t]; ~j; j = ne[j]) {
            int v = e[j];
            if (!st[v] && dist[v] > dist[t] + w[j])
                dist[v] = dist[t] + w[j];
        }
    }
}

int main() {
    cin >> n >> m >> S;
    memset(h, -1, sizeof h);
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }
    
    dijkstra(S);

    for (int i = 1; i <= n; i++) 
        if (dist[i] == 0x3f3f3f3f) cout << INF << ' ';
        else cout << dist[i] << ' ';
    cout << endl;

    return 0;
}