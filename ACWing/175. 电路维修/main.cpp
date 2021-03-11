#include <iostream>
#include <cstring>
#include <deque>

#define x first
#define y second
using namespace std;

const int N = 510;

int n, m;
char g[N][N];
int dist[N][N];
bool st[N][N];

int bfs() {
    memset(st, false, sizeof st);
    memset(dist, 0x3f, sizeof dist);

    string s = "\\/\\/";
    int dx[] = {-1, -1, 1, 1}, dy[] = {-1, 1, 1, -1};
    int ix[] = {-1, -1, 0, 0}, iy[] = {-1, 0, 0, -1};

    deque<pair<int, int> > dq;
    dq.push_back({0, 0});
    dist[0][0] = 0;

    while (!dq.empty()) {
        auto t = dq.front();
        dq.pop_front();

        int x = t.x, y = t.y;

        if (x == n && y == m) return dist[x][y];

        if (st[x][y]) continue;
        st[x][y] = true;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (0 <= nx && nx <= n && 0 <= ny && ny <= m) {
                int gx = x + ix[i], gy = y + iy[i];
                int w = (g[gx][gy] != s[i]);
                int d = dist[x][y] + w;
                if (d <= dist[nx][ny]) {
                    dist[nx][ny] = d;
                    if (w) dq.push_back({nx, ny});
                    else dq.push_front({nx, ny});
                }
            }
        }
    }

    return -1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> g[i][j];

        if ((n + m) % 2) cout << "NO SOLUTION" << endl;
        else cout << bfs() << endl;
    }

    return 0;
}