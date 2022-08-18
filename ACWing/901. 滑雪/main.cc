#include <iostream>
using namespace std;

const int N = 310;
int R, C;
int a[N][N], f[N][N];
int d[] = {1, 0, -1, 0, 1};

int dfs(int x, int y) {
    if (f[x][y] != 0) return f[x][y];

    f[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        int nx = x + d[i], ny = y + d[i + 1];
        if (1 <= nx && nx <= R && 1 <= ny && ny <= C && a[x][y] > a[nx][ny]) 
            f[x][y] = max(f[x][y], 1 + dfs(nx, ny));
    }

    return f[x][y];
}

int main() {
    cin >> R >> C;

    for (int i = 1; i <= R; i++)
        for (int j = 1; j <= C; j++)
            cin >> a[i][j];
    
    int res = 0;
    for (int i = 1; i <= R; i++)
        for (int j = 1; j <= C; j++)
            res = max(res, dfs(i, j));

    cout << res << endl;

    return 0;
}