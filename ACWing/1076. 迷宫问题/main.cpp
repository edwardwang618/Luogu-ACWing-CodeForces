#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int N = 1010, d[] = {1, 0, -1, 0, 1};
int n;
int a[N][N];
pair<int, int> pre[N][N];
queue<pair<int, int> > q;

void bfs(int x, int y) {
    q.push({x, y});
    memset(pre, -1, sizeof pre);

    pre[x][y] = {x, y};
    while (!q.empty()) {
        auto t = q.front();
        q.pop();
        x = t.first, y = t.second;
        for (int i = 0; i < 4; i++) {
            int nx = x + d[i], ny = y + d[i + 1];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (a[nx][ny]) continue;
            if (pre[nx][ny].first != -1) continue;

            q.push({nx, ny});
            pre[nx][ny] = t;
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];

    bfs(n - 1, n - 1);
    pair<int, int> end = {0, 0};

    while (1) {
        cout << end.first << ' ' << end.second << endl;
        end = pre[end.first][end.second];
        if (end.first == n - 1 && end.second == n - 1) {
            cout << n - 1 << ' ' << n - 1 << endl;
            break;
        }
    }
    
    return 0;
}