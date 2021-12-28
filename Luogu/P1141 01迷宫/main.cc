#include <iostream>
#include <cstring>
using namespace std;

const int N = 1e3 + 10;
int d[] = {-1, 0, 1, 0, -1};
int n, m;
char g[N][N];
int p[N * N], sz[N * N];

int get(int x, int y) {
    return x * n + y;
}

int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%s", g[i]);

    for (int i = 0; i < n * n; i++) {
        p[i] = i;
        sz[i] = 1;
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < 4; k++) {
                int ni = i + d[k], nj = j + d[k + 1];
                if (0 <= ni && ni < n && 0 <= nj && nj < n && g[i][j] != g[ni][nj]) {
                    int px = find(get(i, j)), py = find(get(ni, nj));
                    if (px != py) {
                        p[px] = py;
                        sz[py] += sz[px];
                    }
                }
            }


    while (m--) {
        int x, y;
        scanf("%d%d", &x, &y);
        x--, y--;
        printf("%d\n", sz[find(get(x, y))]);
    }

    return 0;
}