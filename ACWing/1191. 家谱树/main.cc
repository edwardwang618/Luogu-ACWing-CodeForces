#include <iostream>
#include <cstring>
using namespace std;

const int N = 110, M = N * N;
int n, m;
int h[N], e[M], ne[M], idx;
int q[N];
int d[N];

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
    cin >> n;
    memset(h, -1, sizeof h);
    for (int i = 1; i <= n; i++) {
        int s;
        while (cin >> s, s) {
            add(i, s);
            d[s]++;
        }
    }

    topsort();
    for (int i = 0; i < n; i++) printf("%d ", q[i]);

    return 0;
}