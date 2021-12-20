#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

const int N = 510;

struct State {
    int x, y, lie;
};
int n, m;
char g[N][N];
int dist[N][N][3];

int bfs(State &start, State &end) {
    memset(dist, 0x3f, sizeof dist);
    dist[start.x][start.y][start.lie] = 0;
    queue<State> q;
    q.push(start);

    int d[3][4][3] = {
        {{-2, 0, 2}, {0, 1, 1}, {1, 0, 2}, {0, -2, 1}},
        {{-1, 0, 1}, {0, 2, 0}, {1, 0, 1}, {0, -1, 0}},
        {{-1, 0, 0}, {0, 1, 2}, {2, 0, 0}, {0, -1, 2}}
    };

    while (q.size()) {
        auto t = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            State next = {t.x + d[t.lie][i][0], t.y + d[t.lie][i][1], d[t.lie][i][2]};
            int x = next.x, y = next.y, lie = next.lie;
            if (!(0 <= x && x < n && 0 <= y && y < m ) || g[x][y] == '#') continue;
            if (!lie && g[x][y] == 'E') continue;
            if (lie == 1 && (y + 1 >= m || g[x][y + 1] == '#')) continue;
            if (lie == 2 && (x + 1 >= n || g[x + 1][y] == '#')) continue;

            if (dist[x][y][lie] > dist[t.x][t.y][t.lie] + 1) {
                dist[x][y][lie] = dist[t.x][t.y][t.lie] + 1;
                q.push(next);
            }
        }
    }

    if (dist[end.x][end.y][0] == 0x3f3f3f3f) return -1;
    else return dist[end.x][end.y][0];
}

int main() {
    while (scanf("%d%d", &n, &m), n || m) {
        for (int i = 0; i < n; i++) cin >> g[i];

        State start = {-1}, end;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                if (g[i][j] == 'X' && start.x == -1) {
                    if (g[i][j + 1] == 'X') start = {i, j, 1};
                    else if (g[i + 1][j] == 'X') start = {i, j, 2};
                    else start = {i, j, 0};
                } else if (g[i][j] == 'O') end = {i, j, 0};
            }
        
        int res = bfs(start, end);
        if (res == -1) puts("Impossible");
        else printf("%d\n", res);
    }

    return 0;
}