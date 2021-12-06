#include <iostream>
using namespace std;

const int N = 1e4 + 10;
int n;
int p[N];

int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int k;
        scanf("%d", &k);
        for (int i = 1, x = 0; i <= k; i++) {
            int y;
            scanf("%d", &y);
            if (i == 1) x = y;
            if (!p[y]) p[y] = y;
            if (i > 1) {
                int px = find(x), py = find(y);
                p[px] = py;
            }
        }
    }

    int trcnt = 0, bcnt = 0;
    for (int i = 1; i < N; i++) {
        if (p[i]) bcnt++;
        if (p[i] == i) trcnt++;
    }

    printf("%d %d\n", trcnt, bcnt);
    int q;
    scanf("%d", &q);
    while (q--) {
        int x, y;
        scanf("%d%d", &x, &y);
        int px = find(x), py = find(y);
        if (px == py) puts("Yes");
        else puts("No");
    }

    return 0;
}