#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
using PII = pair<int, int>;

const int N = 22;
struct Node {
    int x, y, dir;
};
int n, m;
char g[N][N];
Node pre[N][N][4];
int pre_man[N][N];
vector<int> path[N][N][4];
bool vis[N][N][4], vis_man[N][N];
PII dist[N][N][4];
int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
char ops[] = "NSWE";

bool check(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m && g[x][y] != '#';
}

int bfs_man(PII start, PII end, PII box, vector<int> &seq) {
    memset(vis_man, 0, sizeof vis_man);
    memset(pre_man, -1, sizeof pre_man);

    if (start == end) return 0;

    queue<PII> q;
    q.push(start);
    vis_man[start.first][start.second] = true;
    vis_man[box.first][box.second] = true;

    while (q.size()) {
        auto t = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            int x = t.first, y = t.second;
            int a = x + dx[i], b = y + dy[i];
            if (check(a, b) && !vis_man[a][b]) {
                vis_man[a][b] = true;
                pre_man[a][b] = i;
                if (a == end.first && b == end.second) {
                    x = a, y = b;
                    while (pre_man[x][y] != -1) {
                        int dir = pre_man[x][y];
                        seq.push_back(dir);
                        x -= dx[dir], y -= dy[dir];
                    }
                    return seq.size();
                }

                q.push({a, b});
            }
        }
    }

    return -1;
}

bool bfs_box(PII man, PII box, Node &end) {
    memset(vis, 0, sizeof vis);

    queue<Node> q;
    for (int i = 0; i < 4; i++) {
        int x = box.first, y = box.second;
        // (a, b)是人要走到的推箱子的位置
        int a = x - dx[i], b = y - dy[i];
        // (j, k)是箱子要被推到的位置
        int j = x + dx[i], k = y + dy[i];
        vector<int> seq;
        if (check(a, b) && check(j, k) && ~bfs_man(man, {a, b}, box, seq)) {
            dist[j][k][i] = {1, seq.size()};
            path[j][k][i] = seq;
            pre[j][k][i] = {x, y, -1};
            if (g[j][k] == 'T') {
                end = {j, k, i};
                return true;
            }

            vis[j][k][i] = true;
            q.push({j, k, i});
        }
    }

    bool success = false;
    PII best_dis = {1e9, 1e9};
    while (q.size()) {
        auto t = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            // ren
            int a = t.x - dx[i], b = t.y - dy[i];
            // xiang
            int j = t.x + dx[i], k = t.y + dy[i];
            if (check(a, b) && check(j, k)) {
                vector<int> seq;
                int dis = bfs_man({t.x - dx[t.dir], t.y - dy[t.dir]}, {a, b}, {t.x, t.y}, seq);
                if (~dis) {
                    PII td = {dist[t.x][t.y][t.dir].first + 1, dist[t.x][t.y][t.dir].second + dis};
                    if (!vis[j][k][i] || dist[j][k][i] > td) {
                        path[j][k][i] = seq;
                        pre[j][k][i] = t;
                        dist[j][k][i] = td;

                        if (g[j][k] == 'T') {
                            success = true;
                            if (best_dis > dist[j][k][i]) {
                                end = {j, k, i};
                                best_dis = dist[j][k][i];
                            }

                            vis[j][k][i] = true;
                        }

                        if (!vis[j][k][i] && !success) {
                            vis[j][k][i] = true;
                            q.push({j, k, i});
                        }
                    }
                }
            }
        }
    }

    return success;
}

int main() {
    int T = 1;
    while (scanf("%d%d", &n, &m), n || m) {
        printf("Maze #%d\n", T++);

        for (int i = 0; i < n; i++) cin >> g[i];

        PII man, box;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (g[i][j] == 'S') man = {i, j};
                else if (g[i][j] == 'B') box = {i, j};

        Node end;
        if (!bfs_box(man, box, end)) puts("Impossible.");
        else {
            string res;
            while (!(end.x == box.first && end.y == box.second && end.dir == -1)) {
                res += ops[end.dir];
                for (auto dir: path[end.x][end.y][end.dir]) res += ops[dir] + 32;
                end = pre[end.x][end.y][end.dir];
            }
            reverse(res.begin(), res.end());
            cout << res << endl;
        }
        puts("");
    }

    return 0;
}