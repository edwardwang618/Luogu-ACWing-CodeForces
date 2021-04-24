#include <iostream>
using namespace std;

const int N = 1010, M = N * N, K = 2 * N * N;
int n, m, cnt;
int ids[N][N];
struct Edge {
    int a, b, w;
} e[K];
int p[M];

int find(int x) {
    if (x != p[x]) p[x] = find(p[x]);
    return p[x];
}

void get_edges() {
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1}, w[4] = {1, 2, 1, 2};
    for (int r = 0; r < 2; r++)
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
                for (int d = 0; d < 4; d++)
                    if (d % 2 == r) {
                        int x = i + dx[d], y = j + dy[d];
                        if (1 <= x && x <= m && 1 <= y && y <= n) {
                            int a = ids[i][j], b = ids[x][y];
                            if (a < b) e[cnt++] = {a, b, w[d]};
                        }
                    }
}

int main() {
    cin >> m >> n;
    for (int i = 1, t = 1; i <= m; i++)
        for (int j = 1; j <= n; j++, t++)
            ids[i][j] = t;

    for (int i = 1; i <= m * n; i++) p[i] = i;

    int x1, y1, x2, y2;
    while (cin >> x1 >> y1 >> x2 >> y2) {
        int a = ids[x1][y1], b = ids[x2][y2];
        p[find(a)] = find(b);
    }
    
    get_edges();

    int res = 0;
    for (int i = 0; i < cnt; i++) {
        int pa = find(e[i].a), pb = find(e[i].b);
        if (pa != pb) {
            res += e[i].w;
            p[pa] = p[pb];
        }
    }

    cout << res << endl;

    return 0;
}