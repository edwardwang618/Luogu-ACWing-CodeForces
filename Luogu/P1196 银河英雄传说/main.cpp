#include <iostream>
#include <cstring>
using namespace std;

const int N = 3e4 + 10;
int m;
int p[N], sz[N], d[N];

int find(int x) {
    if (p[x] != x) {
        int fa = find(p[x]);
        d[x] += d[p[x]];
        p[x] = fa;
    }

    return p[x];
}

int main() {
    scanf("%d", &m);
    for (int i = 1; i < N; i++) {
        p[i] = i;
        sz[i] = 1;
    }

    while (m--) {
        char op[2];
        int a, b;
        scanf("%s%d%d", op, &a, &b);
        if (op[0] == 'M') {
            int pa = find(a), pb = find(b);
            d[pa] = sz[pb];
            sz[pb] += sz[pa];
            p[pa] = pb;
        } else {
            int pa = find(a), pb = find(b);
            if (pa != pb) puts("-1");
            else printf("%d\n", a == b ? 0 : abs(d[a] - d[b]) - 1);
        }
    }

    return 0;
}