#include <iostream>
#include <algorithm>
using namespace std;

const int N = 310, M = 8010;
int n, m;
int res;

struct Edge {
    int a, b, w;
    bool operator<(const Edge &t) const {
        return w < t.w;
    }
} e[M];
int p[N];

int find(int x) {
    if (x != p[x]) p[x] = find(p[x]);
    return p[x];
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        e[i] = {a, b, w};
    }

    for (int i = 1; i <= n; i++) p[i] = i;

    sort(e, e + m);

    for (int i = 0; i < m; i++) {
        int pa = find(e[i].a), pb = find(e[i].b);
        if (pa != pb) {
            p[pa] = pb;
            res = e[i].w;
        }
    }

    printf("%d %d\n", n - 1, res);

    return 0;
}