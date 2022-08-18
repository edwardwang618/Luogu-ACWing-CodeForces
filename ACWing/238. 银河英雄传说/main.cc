#include <iostream>
using namespace std;

const int N = 3e4 + 10;
int m;
int p[N], sz[N], d[N];

int find(int x) {
    if (p[x] != x) {
        int root = find(p[x]);
        d[x] += d[p[x]];
        p[x] = root;
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
        int pa = find(a), pb = find(b);
        if (op[0] == 'M') {
            if (pa != pb) {
                p[pa] = pb;
                d[pa] = sz[pb];
                sz[pb] += sz[pa];
            }
        } else {
            if (pa != pb) puts("-1");
            else printf("%d\n", a != b ? abs(d[a] - d[b]) - 1 : 0);
        }
    }

    return 0;
}