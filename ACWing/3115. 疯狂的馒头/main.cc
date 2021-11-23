#include <iostream>
using namespace std;

const int N = 1e6 + 10;
int n, m, _p, _q;
int p[N], color[N];

int find (int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main() {
    scanf("%d%d%d%d", &n, &m, &_p, &_q);

    for (int i = 1; i <= n + 1; i++) p[i] = i;

    for (int i = m; i; i--) {
        int l = (i * _q + _p) % n + 1;
        int r = (i * _p + _q) % n + 1;
        if (l > r) swap(l, r);

        int pa = find(l);
        while (pa <= r) {
            color[pa] = i;
            p[pa] = find(pa + 1);
            pa = find(pa);
        }
    }

    for (int i = 1; i <= n; i++) printf("%d\n", color[i]);
    
    return 0;
}