#include <iostream>
#include <cstring>
using namespace std;

typedef pair<int, int> PII;

const int N = 1010, M = 21010;
int n, m, T;
int h[N], e[M], ne[M], w[M], idx;
int dist[N];
bool st[N];

void add(int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

int dijkstra() {
    memset(dist, 0x3f, sizeof dist);
    memset(st, 0, sizeof st);

    dist[0] = 0;

    for (int i = 0; i <= n; i++) {
        int t = 0x3f3f3f3f, v = 0;
        for (int j = 0; j <= n; j++)
            if (!st[j] && dist[j] < t) 
                t = dist[j], v = j;

        if (v == T) return dist[T];

        st[v] = true;
        for (int i = h[v]; ~i; i = ne[i]) {
            int j = e[i];
            if (!st[j] && dist[j] > dist[v] + w[i])
                dist[j] = dist[v] + w[i];
        }
    }
    
    return -1;
}

int main() {
    while (~scanf("%d%d%d", &n, &m, &T)) {
        memset(h, -1, sizeof h);
        idx = 0;

        while (m--) {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            add(a, b, c);
        }

        int s;
        scanf("%d", &s);
        while (s--) {
            int v;
            scanf("%d", &v);
            add(0, v, 0);
        }
        
        printf("%d\n", dijkstra());
    }

    return 0;
}