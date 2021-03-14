#include <iostream>
#include <cstring>
using namespace std;

const int N = 10;
int dx[] = {-1, -2, -2, -1, 1, 2, 2, 1};
int dy[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int m, n;
bool st[N][N];
int res;

void dfs(int x, int y, int cnt) {
    st[x][y] = true;
    cnt++;

    if (cnt == n * m) res++;
    else 
        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (0 <= nx && nx < n && 0 <= ny && ny < m && !st[nx][ny])
                dfs(nx, ny, cnt);
        }

    st[x][y] = false;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int x, y;
        cin >> n >> m >> x >> y;
        memset(st, false, sizeof st);

        res = 0;
        dfs(x, y, 0);

        cout << res << endl;
    }

    return 0;
}