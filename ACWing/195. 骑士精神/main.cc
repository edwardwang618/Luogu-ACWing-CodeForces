#include <iostream>
using namespace std;

const int INF = 1e9;
int dx[] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[] = {2, 1, -1, -2, -2, -1, 1, 2};
char g[5][5];
string goal[] = {
    "11111", 
    "01111",
    "00*11",
    "00001",
    "00000"};

int h() {
    int cnt = 0;
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            if (g[i][j] != '*' && g[i][j] != goal[i][j]) cnt++;
    return cnt;
}

int dfs(int depth, int x, int y, int max_depth, int &next_depth) {
    int he = h();
    if (!he) return depth;
    if (depth + he > max_depth) {
        next_depth = min(next_depth, depth + he);
        return -1;
    }

    int res = -1;
    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (0 <= nx && nx < 5 && 0 <= ny && ny < 5) {
            swap(g[x][y], g[nx][ny]);
            if (~(res = dfs(depth + 1, nx, ny, max_depth, next_depth))
                return res;
            swap(g[x][y], g[nx][ny]);
        }
    }

    return -1;
}

int main() {
    int T;
    while (T--) {
        for (int i = 0; i < 5; i++) scanf("%s", g[i]);
        int x, y;
        for (int i = 0; i < 5; i++)
            for (int j = 0; j < 5; j++)
                if (g[i][j] == '*') {
                    x = i, y = j;
                    break;
                }
        
        int next_depth = INF, res = -1;
        for (int max_depth = 0, next_depth; max_depth <= 15; max_depth = next_depth) {
            next_depth = INF;
            if (~(res = dfs(0, x, y, max_depth, next_depth))) break;
        }

        printf("%d\n", res);
    }

    return 0;
}