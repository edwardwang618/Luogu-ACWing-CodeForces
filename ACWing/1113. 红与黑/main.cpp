#include <iostream>
using namespace std;

const int N = 25, d[] = {1, 0, -1, 0, 1};
int n, m;
char g[N][N];
int res;

void dfs(int x, int y) {
    res++;
    g[x][y] = '#';
    for (int i = 0; i < 4; i++) {
        int nx = x + d[i], ny = y + d[i + 1];
        if (0 <= nx && nx < m && 0 <= ny && ny < n && g[nx][ny] == '.')
            dfs(nx, ny);
    }
}

int main() {
    while (1) {
        cin >> n >> m;
        if (n == 0 && m == 0) break;

        int x, y;
        for (int i = 0; i < m; i++) 
            for (int j = 0; j < n; j++) {
                cin >> g[i][j];
                if (g[i][j] == '@') x = i, y = j;
            }
        
        res = 0;
        dfs(x, y);
        cout << res << endl;
    }

    return 0;
}