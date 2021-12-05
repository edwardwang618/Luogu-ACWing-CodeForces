#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int n, m;
int p[N];

int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main() {
    int T;
    scanf("%d", &T);
    for (int k = 1; k <= T; k++) {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++) p[i] = i;
        int res = 0;
        for (int i = 1; i <= m; i++) {
            int x, y;
            scanf("%d%d", &x, &y);
            int px = find(x), py = find(y);
            if (px != py) {
                p[px] = py;
                res++;
            }
        }

        res += (n - 1 - res) * 2;
        printf("Case #%d: %d\n", k, res);
    }

    return 0;
}