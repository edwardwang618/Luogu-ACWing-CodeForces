#include <iostream>
#include <cstring>
using namespace std;

typedef pair<int, int> PII;

const int N = 110;
int n, m, k;
PII match[N][N];
bool forb[N][N], st[N][N];

const int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
const int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

bool dfs(int x, int y) {
    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
        if (st[nx][ny] || forb[nx][ny]) continue;

        st[nx][ny] = true;
        PII t = match[nx][ny];
        if (!t.first || dfs(t.first, t.second)) {
            match[nx][ny] = {x, y};
            return true;
        }
    }

    return false;
}

int main() {
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        forb[a][b] = true;
    }
    
    int res = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            if ((i + j) % 2 || forb[i][j]) continue;

            memset(st, 0, sizeof st);
            if (dfs(i, j)) res++;        
        }

    cout << (n * m - k - res) << endl;

    return 0;
}