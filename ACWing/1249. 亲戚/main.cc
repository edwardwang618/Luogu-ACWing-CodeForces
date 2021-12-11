#include <iostream>
using namespace std;

const int N = 2e4 + 10;
int n, m, q;
int p[N];

int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) p[i] = i;
    while (m--) {
        int x, y;
        scanf("%d%d", &x, &y);
        p[find(x)] = find(y);
    }

    scanf("%d", &q);
    while (q--) {
        int x, y;
        scanf("%d%d", &x, &y);
        if (find(x) == find(y)) puts("Yes");
        else puts("No");
    }

    return 0;
}