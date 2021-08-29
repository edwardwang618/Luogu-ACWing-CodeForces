#include <iostream>
using namespace std;

int a[110][110];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int main() {
    int n, m;
    cin >> n >> m;
    for (int x = 0, y = 0, s = 1; s <= m * n; ) {
        for (int i = 0; i < 4; i++) {
            while (s <= m * n) {
                a[x][y] = s++;
                x += dx[i], y += dy[i];
                if (x < 0 || x >= n || y < 0 || y >= m || a[x][y]) {
                    x -= dx[i], y -= dy[i];
                    x += dx[(i + 1) % 4], y += dy[(i + 1) % 4];
                    break;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) printf("%d ", a[i][j]);
        puts("");
    }

    return 0;
}