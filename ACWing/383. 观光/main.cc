#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int N = 1010, M = 10010;

struct Ver {
    int ver, type, dist;
    // 最小堆，所以重载大于号
    bool operator>(const Ver& W) const {
        return dist > W.dist;
    }
};

int n, m, S, T;
int h[N], e[M], ne[M], w[M], idx;
int dist[N][2], cnt[N][2];
bool vis[N][2];

void add(int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void dijkstra() {
    memset(vis, 0, sizeof vis);
    memset(cnt, 0, sizeof cnt);
    memset(dist, 0x3f, sizeof dist);
    dist[S][0] = 0;
    cnt[S][0] = 1;

    priority_queue<Ver, vector<Ver>, greater<Ver> > heap;
    heap.push({S, 0, 0});

    while (heap.size()) {
        auto t = heap.top();
        heap.pop();

        int v = t.ver, type = t.type, d = t.dist, count = cnt[v][type];
        if (vis[v][type]) continue;
        vis[v][type] = true;

        for (int i = h[v]; ~i; i = ne[i]) {
            int j = e[i];
            if (dist[j][0] > d + w[i]) {
                dist[j][1] = dist[j][0], cnt[j][1] = cnt[j][0];
                heap.push({j, 1, dist[j][1]});
                dist[j][0] = d + w[i], cnt[j][0] = count;
                heap.push({j, 0, dist[j][0]});
            } else if (dist[j][0] == d + w[i]) cnt[j][0] += count;
            else if (dist[j][1] > d + w[i]) {
                dist[j][1] = d + w[i], cnt[j][1] = count;
                heap.push({j, 1, dist[j][1]});
            } else if (dist[j][1] == d + w[i]) cnt[j][1] += count;
        }
    }
}

int main() {
    int C;
    cin >> C;
    while (C--) {
        memset(h, -1, sizeof h);
        idx = 0;
        cin >> n >> m;
        for (int i = 0; i < m; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            add(a, b, c);
        }

        cin >> S >> T;
        
        dijkstra();

        int res = cnt[T][0];
        if (dist[T][0] == dist[T][1] - 1) res += cnt[T][1];
        cout << res << endl;
    }

    return 0;
}