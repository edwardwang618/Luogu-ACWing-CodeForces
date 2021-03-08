#include <iostream>
#include <queue>
using namespace std;

const int N = 1010;
int h[N][N];
int n;
queue<pair<int, int> > q;
bool st[N][N];

void bfs(int x, int y, bool& has_higher, bool& has_lower) {
    st[x][y] = true;
    q.push({x, y});
    while (!q.empty()) {
        auto t = q.front();
        q.pop();
        x = t.first, y = t.second;
        for (int dx = -1; dx <= 1; dx++)
            for (int dy = -1; dy <= 1; dy++) {
                if (dx == 0 && dy == 0) continue;

                int nx = x + dx, ny = y + dy;
                if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                if (h[nx][ny] != h[x][y]) {
                    if (h[nx][ny] > h[x][y]) has_higher = true;
                    else has_lower = true;
                } else if (!st[nx][ny]) {
                    st[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> h[i][j];

    int peak = 0, valley = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (!st[i][j]) {
                bool has_higher = false, has_lower = false;
                bfs(i, j, has_higher, has_lower);
                if (!has_higher) peak++;
                if (!has_lower) valley++;
            }

    cout << peak << ' ' << valley << endl;

    return 0;
}