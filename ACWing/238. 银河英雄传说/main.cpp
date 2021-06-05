#include <iostream>
#include <cstring>
using namespace std;

const int N = 30010;
int m;
int p[N], sz[N], d[N];

int find(int x) {
    if (p[x] == x) return x;

    int root = find(p[x]);
    d[x] += d[p[x]];
    return p[x] = root;
}

void merge(int x, int y) {
    x = find(x), y = find(y);
    p[x] = y, d[x] = sz[y];
    sz[y] += sz[x];
}

int main() {
    for (int i = 1; i < N; i++) p[i] = i, sz[i] = 1;

    scanf("%d", &m);
    while (m--) {
        char op[2];
        int a, b;
        scanf("%s%d%d", op, &a, &b);
        if (op[0] == 'M') {
            merge(a, b);
        } else {
            if (a == b) puts("0");

            int pa = find(a), pb = find(b);
            if (pa != pb) puts("-1");
            else printf("%d\n", abs(d[a]- d[b]) - 1);
        }
    }

    return 0;
}