#include <iostream>
#include <cstring>
#include <deque>
#include <set>
using namespace std;

typedef pair<int, int> PII;

const int N = 11, M = N * N, E = 400, P = 1 << 10;
int n, m, p, k;
int h[M], e[E], w[E], ne[E], idx;
int g[N][N], key[M];
int dist[M][P];
bool st[M][P];
set<PII> edges;

void add(int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void build() {
    int d[] = {1, 0, -1, 0, 1};
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            for (int u = 0; u < 4; u++) {
                int nx = i + d[u], ny = j + d[u + 1];
                if (1 <= nx && nx <= n && 1 <= ny && ny <= m) {
                    int a = g[i][j], b = g[nx][ny];
                    if (!edges.count({a, b})) add(a, b, 0);

                }
            }
}

int bfs() {
    memset(dist, 0x3f, sizeof dist);
    dist[1][0] = 0;

    deque<PII> dq;
    dq.push_back({1, 0});

    while (dq.size()) {
        auto t = dq.front();
        dq.pop_front();

        if (st[t.first][t.second]) continue;

        if (t.first == n * m) return dist[t.first][t.second];

        st[t.first][t.second] = true;

        if (key[t.first] && (t.second & key[t.first]) != key[t.first]) {
            int state = t.second | key[t.first];
            if (dist[t.first][state] > dist[t.first][t.second]) {
                dist[t.first][state] = dist[t.first][t.second];
                dq.push_front({t.first, state});
            }
        } else
            for (int i = h[t.first]; ~i; i = ne[i]) {
                int j = e[i];
                if (st[j][t.second]) continue;
                if (w[i] && !(t.second >> w[i] - 1 & 1)) continue;
                if (dist[j][t.second] > dist[t.first][t.second] + 1) {
                    dist[j][t.second] = dist[t.first][t.second] + 1;
                    dq.push_back({j, t.second});
                }
            }
    }

    return -1;
}

int main() {
    scanf("%d%d%d%d", &n, &m, &p, &k);

    for (int i = 1, t = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            g[i][j] = t++;

    memset(h, -1, sizeof h);

    while (k--) {
        int x1, y1, x2, y2, c;
        scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &c);
        int a = g[x1][y1], b = g[x2][y2];
        edges.insert({a, b}), edges.insert({b, a});
        if (c) add(a, b, c), add(b, a, c);
    }

    build();

    int s;
    scanf("%d", &s);
    while (s--) {
        int x, y, id;
        scanf("%d%d%d", &x, &y, &id);
        key[g[x][y]] |= 1 << id - 1;
    }

    printf("%d\n", bfs());

    return 0;
}