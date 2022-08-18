#include <iostream>
#include <cstring>
using namespace std;

const int N = 110, d[] = {1, 0, -1, 0, 1};
char a[N][N];
bool st[N][N];
int n;
int sx, sy, ex, ey;

bool dfs(int x, int y) {
    if (x == ex && y == ey) return true;

    st[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int nx = x + d[i], ny = y + d[i + 1];
        if (0 <= nx && nx < n && 0 <= ny && ny < n && a[nx][ny] != '#' && !st[nx][ny]) 
            if (dfs(nx, ny)) return true;
    }

    return false;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> a[i][j];
        cin >> sx >> sy >> ex >> ey;

        memset(st, false, sizeof st);

        bool res = false;
        if (a[sx][sy] == '#' || a[ex][ey] == '#') res = false;
        else res = dfs(sx, sy);

        cout << (res ? "YES" : "NO") << endl;
    }

    return 0;
}