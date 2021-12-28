#include <iostream>
using namespace std;

const int N = 1e6 + 10, INF = 2e9;
int dx[] = {1, 0, 0, -1};
int dy[] = {0, -1, 1, 0};
string op = "dlru";
int board[N], goal[N];
string path;
int next_depth;

int dis() {
    int dis = 0;
    for (int i = 0; i < 9; i++)
        if (board[i] != 9) {
            int x = i / 3, y = i % 3;
            int xx = goal[board[i]] / 3, yy = goal[board[i]] % 3;
            dis += abs(x - xx) + abs(y - yy);
        }

    return dis;
}

bool dfs(int idx, int depth, int pre, int max_depth) {
    int h = dis();
    if (depth + h > max_depth) {
        next_depth = min(next_depth, depth + h);
        return false;
    }

    if (!h) return true;

    int x = idx / 3, y = idx % 3;
    for (int i = 0; i < 4; i++) {
        if (i + pre == 3) continue;
        int nx = x + dx[i], ny = y + dy[i];
        if (0 <= nx && nx < 3 && 0 <= ny && ny < 3) {
            int nidx = nx * 3 + ny;
            swap(board[idx], board[nidx]);
            path += op[i];
            if (dfs(nx * 3 + ny, depth + 1, i, max_depth)) return true;
            swap(board[idx], board[nidx]);
            path.pop_back();
        }
    }

    return false;
}

int main() {
    int T;
    char str[50];
    scanf("%d", &T);
    for (int k = 1; k <= T; k++) {
        int idx;
        scanf("%s", str);
        for (int i = 0; i < 9; i++) {
            if (str[i] == 'X') board[i] = 9, idx = i;
            else board[i] = str[i] - '0';
        }

        scanf("%s", str);
        for (int i = 0; i < 9; i++) {
            if (str[i] == 'X') goal[9] = i;
            else goal[str[i] - '0'] = i;
        }

        path = "";
        for (int max_depth = dis();; max_depth = next_depth) {
            next_depth = INF;
            if (dfs(idx, 0, INF, max_depth)) break;
        }

        printf("Case %d: %d\n", k, path.size());
        cout << path << endl;
    }
}