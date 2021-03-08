#include <iostream>
#include <queue>
using namespace std;

const int N = 55, d[] = {0, -1, 0, 1, 0};
int m, n;
int a[N][N];
bool st[N][N];
queue<pair<int, int> > q;

int bfs(int x, int y) {
    int area = 1;
    q.push({x, y});
    st[x][y] = true;

    while (!q.empty()) {
        auto t = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = t.first + d[i], ny = t.second + d[i + 1];
            if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
            if (st[nx][ny]) continue;
            if (a[t.first][t.second] >> i & 1) continue;

            q.push({nx, ny});
            st[nx][ny] = true;
            area++;
        }
    }

    return area;
}

int main() {
    cin >> m >> n;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];

    int cnt = 0, area = 0;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (!st[i][j]) {
                area = max(area, bfs(i, j));
                cnt++;
            }

    cout << cnt << endl;
    cout << area << endl;

    return 0;
}