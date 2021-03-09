#include <iostream>
#include <queue>

#define x first
#define y second
using namespace std;

typedef pair<int, int> PII;

const int N = 160;
int C, R;
char a[N][N];
queue<PII> q;
bool st[N][N];

int bfs(PII start, PII end) {
    int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
    int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
    q.push(start);

    int res = 0;
    while (!q.empty()) {
        res++;
        int size = q.size();
        for (int i = 0; i < size; i++) {
            auto t = q.front();
            q.pop();
            for (int j = 0; j < 8; j++) {
                int nx = t.x + dx[j], ny = t.y + dy[j];
                if (0 <= nx && nx < R && 0 <= ny && ny < C && !st[nx][ny] && a[nx][ny] != '*') {
                    if (nx == end.x && ny == end.y) return res;

                    st[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
    }
    
    return -1;
}

int main() {
    cin >> C >> R;
    PII start, end;
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++) {
            cin >> a[i][j];
            if (a[i][j] == 'K') start = {i, j};
            else if (a[i][j] == 'H') end = {i, j};
        }

    cout << bfs(start, end) << endl;

    return 0;
}