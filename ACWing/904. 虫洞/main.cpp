#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int N = 510, M = 5210;
int n, m1, m2;
int h[N], e[M], ne[M], w[M], idx;
int dist[N], cnt[N];
bool st[N];

void init() {
    memset(h, -1, sizeof h);
    idx = 0;

    memset(dist, 0, sizeof dist);
    memset(st, 0, sizeof st);
    memset(cnt, 0, sizeof cnt);
}

void add(int a, int b, int c) {
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}

bool spfa() {
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        q.push(i);
        st[i] = true;
    }

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
        init();

        cin >> n >> m1 >> m2;
        while (m1--) {
            int a, b, c;
            cin >> a >> b >> c;
            add(a, b, c), add(b, a, c);
        }
        while (m2--) {
            int a, b, c;
            cin >> a >> b >> c;
            add(a, b, -c);
        }
        
        cout << (spfa() ? "YES" : "NO") << endl;
    }

    return 0;
}