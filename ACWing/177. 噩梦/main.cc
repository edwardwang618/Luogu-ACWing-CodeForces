#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
using PII = pair<int, int>;

const int N = 810;
int n, m, cnt;
char g[N][N];
int vis[N][N];
PII ghost[2], boy, girl;
int d[] = {-1, 0, 1, 0, -1};

bool check(int x, int y, int step) {
    if (x < 0 || x >= n || y < 0 || y >= m || g[x][y] == 'X') return false;
    for (int i = 0; i < 2; i++)
        if (abs(x - ghost[i].first) + abs(y - ghost[i].second) <= step * 2) return false;
    return true;
}

int bfs() {
    cnt = 0;
    memset(vis, 0, sizeof vis);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (g[i][j] == 'M') boy = {i, j};
            else if (g[i][j] == 'G') girl = {i, j};
            else if (g[i][j] == 'Z') ghost[cnt++] = {i, j};
    
    int step = 0;
    queue<PII> qb, qg;
    qb.push(boy), qg.push(girl);
    while (qb.size() && qg.size()) {
        step++;
        for (int i = 0; i < 3; i++)
            for (int j = qb.size(); j; j--) {
                auto t = qb.front(); qb.pop();
                int x = t.first, y = t.second;
                if (!check(x, y, step)) continue;
                for (int k = 0; k < 4; k++) {
                    int nx = x + d[k], ny = y + d[k + 1];
                    if (check(nx, ny, step)) {
                        if (vis[nx][ny] == 2) return step;
                        if (!vis[nx][ny]) {
                            vis[nx][ny] = 1;
                            qb.push({nx, ny});
                        }
                    }
                }
            }

        for (int j = qg.size(); j; j--) {
            auto t = qg.front(); qg.pop();
            int x = t.first, y = t.second;
            if (!check(x, y, step)) continue;
            for (int k = 0; k < 4; k++) {
                int nx = x + d[k], ny = y + d[k + 1];
                if (check(nx, ny, step)) {
                    if (vis[nx][ny] == 1) return step;
                    if (!vis[nx][ny]) {
                        vis[nx][ny] = 2;
                        qg.push({nx, ny});
                    }
                }
            }
        }
    }

    return -1;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; i++) scanf("%s", g[i]);
        printf("%d\n", bfs());
    }

    return 0;
}