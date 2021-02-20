#include <iostream>
using namespace std;

const int N = 1010;
char a[N][N];
int m, n;
int res;

void dfs(int x, int y) {
    a[x][y] = '.';
    for (int dx = -1; dx <= 1; dx++) 
        for (int dy = -1; dy <= 1; dy++) {
            int nx = x + dx, ny = y + dy;
            if (1 <= nx && nx <= m && 1 <= ny && ny <= n && a[nx][ny] == 'W')
                dfs(nx, ny);
        }
}

int main() {
    cin >> m >> n;

    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];

    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            if (a[i][j] == 'W') {
                dfs(i, j);
                res++;
            }
    
    cout << res << endl;

    return 0;
}