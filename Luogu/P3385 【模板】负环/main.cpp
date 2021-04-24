#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int N = 2010, M = 3010 * 2;
int n, m;
int h[N], e[M], ne[M], w[M], idx;
int dist[N], cnt[N];
bool st[N];

void add(int a, int b, int c) {
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}

bool spfa() {
    queue<int> q;
    q.push(1);

    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;

    memset(cnt, 0, sizeof cnt);
    memset(st, 0, sizeof st);

    while (q.size()) {
        int t = q.front(); q.pop();
        st[t] = false;

        for (int i = h[t]; ~i; i = ne[i]) {
            int j = e[i];
            if (dist[j] > dist[t] + w[i]) {
                dist[j] = dist[t] + w[i];
                cnt[j] = cnt[t] + 1;

                if (cnt[j] >= n) return true;

                if (!st[j]) {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }
    
    return false;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        memset(h, -1, sizeof h);
        idx = 0;

        cin >> n >> m;
        for (int i = 0; i < m; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            add(a, b, c);
            if (c >= 0) add(b, a, c);
        }

        printf("%s\n", spfa() ? "YES" : "NO");
    }
}