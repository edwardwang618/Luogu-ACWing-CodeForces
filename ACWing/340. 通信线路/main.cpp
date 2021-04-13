#include <iostream>
#include <cstring>
#include <deque>
using namespace std;

const int N = 1010, M = 20010;
int n, m, k;
int h[N], e[M], ne[M], w[M], idx;
bool st[N];
int dist[N];

void add(int a, int b, int c) {
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}

int bfs(int bound) {
    memset(dist, 0x3f, sizeof dist);
    memset(st, 0, sizeof st);

    deque<int> dq;
    dq.push_back(1);
    dist[1] = 0;

    while (dq.size()) {
        int t = dq.front();
        dq.pop_front();

        if (st[t]) continue;
        if (t == n) return dist[t];

        st[t] = true;

        for (int i = h[t]; ~i; i = ne[i]) {
            int j = e[i], ed = w[i] > bound ? 1 : 0;
            if (dist[j] > dist[t] + ed) {
                dist[j] = dist[t] + ed;
                if (ed) dq.push_back(j);
                else dq.push_front(j);
            }
        }
    }
    
    return 0x3f3f3f3f;
}

int main() {
    cin >> n >> m >> k;
    memset(h, -1, sizeof h);

    int r = 0;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c), add(b, a, c);
        r = max(r, c);
    }

    int l = 0;
    while (l < r) {
        int mid = l + (r - l >> 1);
        int d = bfs(mid);
        if (d == 0x3f3f3f3f) {
            r = d;
            break;
        }

        if (d <= k) r = mid;
        else l = mid + 1;
    }
    
    if (r == 0x3f3f3f3f) cout << -1 << endl;
    else cout << r << endl;

    return 0;
}