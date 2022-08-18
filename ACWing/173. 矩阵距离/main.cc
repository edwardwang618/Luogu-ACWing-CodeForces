#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int N = 1010, d[] = {1, 0, -1, 0, 1};
int n, m;
char a[N][N];
int dist[N][N];

void bfs() {
    memset(dist, -1, sizeof dist);

    queue<pair<int, int>> q;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (a[i][j] == '1') {
                q.push({i, j});
                dist[i][j] = 0;
            }

    while (!q.empty()) {
        auto t = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = t.first + d[i], ny = t.second + d[i + 1];
            if (1 <= nx && nx <= n && 1 <= ny && ny <= m && a[nx][ny] == '0' && dist[nx][ny] == -1) {
                dist[nx][ny] = dist[t.first][t.second] + 1;
                q.push({nx, ny});
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];

    bfs();

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++)
            cout << dist[i][j] << ' ';
        cout << endl;
    }

    return 0;
}