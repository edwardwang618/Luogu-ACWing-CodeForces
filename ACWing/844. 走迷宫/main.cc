#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> PII;
const int N = 110;
int a[N][N];
bool visited[N][N];

int main() {
    int m, n;
    cin >> m >> n;

    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];

    if (m == 1 && n == 1) {
        cout << 0 << endl;
        return 0;
    }

    int res = 0;
    queue<PII> q;
    q.push(make_pair(1, 1));
    int d[] = {1, 0, -1, 0, 1};
    while (!q.empty()) {
        res++;
        int s = q.size();
        for (int i = 0; i < s; i++) {
            PII pair = q.front();
            q.pop();
            for (int j = 0; j < 4; j++) {
                int nextX = pair.first + d[j], nextY = pair.second + d[j + 1];
                if (nextX == m && nextY == n) {
                    cout << res << endl;
                    return 0;
                }

                if (1 <= nextX && nextX <= m && 1 <= nextY && nextY <= n && a[nextX][nextY] == 0 && !visited[nextX][nextY]) {
                    visited[nextX][nextY] = true;
                    q.push(make_pair(nextX, nextY));
                }
            }
        }
    }

    return 0;
}