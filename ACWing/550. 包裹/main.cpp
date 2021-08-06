#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int N = 260, d[] = {-1, 0, 1, 0, -1}, INF = 1e9;
int n, m;
string g[N];
int dist[N][N];

void bfs(int k) {
    queue<pair<int, int>> q;
    memset(dist, -1, sizeof dist);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (g[i][j] == '1') {
                q.push({i, j});
                dist[i][j] = 0;
            }
    
    while (q.size()) {
        auto t = q.front(); q.pop();
        int x = t.first, y = t.second;
        int dis = dist[x][y];
        if (dis == k) continue;
        for (int i = 0; i < 4; i++) {
            int nx = x + d[i], ny = y + d[i + 1];
            if (0 <= nx && nx < n && 0 <= ny && ny < m && dist[nx][ny] == -1) {
                dist[nx][ny] = dis + 1;
                q.push({nx, ny});
            }
        }
    }
}

bool check(int k) {
    bfs(k);
    int min_sum = INF, max_sum = -INF;
    int min_sub = INF, max_sub = -INF;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (dist[i][j] == -1) {
                min_sum = min(min_sum, i + j);
                max_sum = max(max_sum, i + j);
                min_sub = min(min_sub, i - j);
                max_sub = max(max_sub, i - j);
            }
    
    if (min_sum == INF) return true;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (g[i][j] == '0') {
                int sum = max(abs(i + j - min_sum), abs(i + j - max_sum));
                int sub = max(abs(i - j - min_sub), abs(i - j - max_sub));
                if (max(sum, sub) <= k) return true;
            }
    
    return false;
}

int main() {
    int T;
    scanf("%d", &T);
    for (int C = 1; C <= T; C++) {
        scanf("%d%d", &n, &m);
        for (int i = 0; i <= n; i++) 
            cin >> g[i];
        
        int l = 0, r = n + m;
        while (l < r) {
            int mid = l + (r - l >> 1);
            if (check(mid)) r = mid;
            else l = mid + 1;
        }

        printf("Case #%d: %d\n", C, l);
    }

    return 0;
}