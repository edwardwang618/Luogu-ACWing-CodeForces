#include <iostream>
#include <cstring>
using namespace std;

const int N = 1010, M = 21010, INF = 0x3f3f3f3f;
int n, m1, m2;
int h[N], e[M], ne[M], w[M], idx;
int q[N], cnt[N];
int dist[N];
bool st[N];

void add(int a, int b, int c) {
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}

bool spfa(int sz) {
    memset(dist, 0x3f, sizeof dist);
    memset(cnt, 0, sizeof cnt);
    memset(st, 0, sizeof st);

    int hh = 0, tt = 0;
    for (int i = 1; i <= sz; i++) {
        dist[i] = 0;
        q[tt++] = i;
        st[i] = true;
    }

    while (hh != tt) {
        int t = q[hh++];
        if (hh == N) hh = 0;
        st[t] = false;
        for (int i = h[t]; ~i; i = ne[i]) {
            int v = e[i];
            if (dist[v] > dist[t] + w[i]) {
                dist[v] = dist[t] + w[i];
                cnt[v] = cnt[t] + 1;
                if (cnt[v] >= n) return false;

                if (!st[v]) {
                    q[tt++] = v;
                    if (tt == N) tt = 0;
                    st[v] = true;
                }
            }
        }
    }

    return true;
}

int main() {
    scanf("%d%d%d", &n, &m1, &m2);
    memset(h, -1, sizeof h);
    for (int i = 1; i < n; i++) add(i + 1, i, 0);
    while (m1--) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        if (b < a) swap(a, b);
        add(a, b, c);
    }
    while (m2--) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        if (b < a) swap(a, b);
        add(b, a, -c);
    }
    
    if (!spfa(n)) puts("-1");
    else if (spfa(1) && dist[n] == INF) puts("-2");
    else printf("%d\n", dist[n]); 

    return 0;
}