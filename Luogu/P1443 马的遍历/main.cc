#include <iostream>
#include <cstring>
using namespace std;
using PII = pair<int, int>;

const int N = 410;
int dx[] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[] = {2, 1, -1, -2, -2, -1, 1, 2};
int n, m, x, y;
int dist[N][N];
PII q[N * N];
int hh, tt;

int main() {
    memset(dist, -1, sizeof dist);
    scanf("%d%d%d%d", &n, &m, &x, &y);
    q[tt++] = {x, y};
    dist[x][y] = 0;
    while (hh < tt) {
        auto t = q[hh++];
        x = t.first, y = t.second;
        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (1 <= nx && nx <= n && 1 <= ny && ny <= m && dist[nx][ny] == -1) {
                dist[nx][ny] = dist[x][y] + 1;
                q[tt++] = {nx, ny};
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++)
            printf("%-5d", dist[i][j]);
        puts("");
    }

    return 0;
}