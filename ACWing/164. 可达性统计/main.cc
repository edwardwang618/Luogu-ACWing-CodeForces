#include <iostream>
#include <cstring>
#include <bitset>
using namespace std;

const int N = 30010, M = N;
int n, m;
int h[N], e[M], ne[M], idx;
int q[N];
int d[N];
bitset<N> f[N];

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void topsort() {
    int hh = 0, tt = 0;
    for (int i = 1; i <= n; i++) 
        if (!d[i])
            q[tt++] = i;
    
    while (hh < tt) {
        int t = q[hh++];
        for (int i = h[t]; ~i; i = ne[i]) {
            int v = e[i];
            if (--d[v] == 0) q[tt++] = v;
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);
    memset(h, -1, sizeof h);
    while (m--) {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);
        d[b]++;
    }

    topsort();
    
    for (int i = n - 1; i >= 0; i--) {
        int v = q[i];
        f[v][v] = 1;
        for (int j = h[v]; ~j; j = ne[j])
            f[v] |= f[e[j]];
    }

    for (int i = 1; i <= n; i++) printf("%d\n", f[i].count());

    return 0;
}