#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
using PII = pair<int, int>;

const int N = 1010;
int n, m, k, d;
int dist[N][N], cus[N][N];
int dir[] = {-1, 0, 1, 0, -1};
queue<PII> q;

long bfs() {
    long cost = 0;
    while (q.size()) {
        auto t = q.front(); q.pop();
        int x = t.first, y = t.second;
        for (int i = 0; i < 4; i++) {
            int nx = x + dir[i], ny = y + dir[i + 1];
            if (1 <= nx && nx <= n && 1 <= ny && ny <= n && dist[nx][ny] == -1) {
                dist[nx][ny] = dist[x][y] + 1;
                if (cus[nx][ny]) cost += dist[nx][ny] * cus[nx][ny];
                q.push({nx, ny});
            }
        }
    }
    
    return cost;
}

int main() {
    memset(dist, -1, sizeof dist);
    scanf("%d%d%d%d", &n, &m, &k, &d);
    while (m--) {
        int x, y;
        scanf("%d%d", &x, &y);
        q.push({x, y});
        dist[x][y] = 0;
    }
    while (k--) {
        int x, y, c;
        scanf("%d%d%d", &x, &y, &c);
        cus[x][y] += c;
    }
    while (d--) {
        int x, y;
        scanf("%d%d", &x, &y);
        dist[x][y] = 0x3f3f3f3f;
    }
    
    printf("%ld\n", bfs());

    return 0;
}