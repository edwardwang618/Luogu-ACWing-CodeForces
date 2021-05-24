#include <iostream>
#include <cstring>
using namespace std;

const int N = 30, M = 100;
int n;
int h[N], e[M], ne[M], w[M], idx;
int r[N], num[N];
int dist[N];
int q[N], cnt[N];
bool st[N];

void add(int a, int b, int c) {
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}

void build(int s24) {
    memset(h, -1, sizeof h);
    idx = 0;

    for (int i = 1; i <= 24; i++) {
        add(i - 1, i, 0);
        add(i, i - 1, -num[i]);
    }

    for (int i = 8; i <= 24; i++) add(i - 8, i, r[i]);
    for (int i = 1; i <= 7; i++) add(i + 16, i, -s24 + r[i]);

    add(0, 24, s24);
    add(24, 0, -s24);
}

bool spfa(int s24) {
    build(s24);
    memset(st, 0, sizeof st);
    memset(cnt, 0, sizeof cnt);
    memset(dist, -0x3f, sizeof dist);
    dist[0] = 0;

    int hh = 0, tt = 0;
    q[tt++] = 0;
    while (hh != tt) {
        int t = q[hh++];
        if (hh == N) hh = 0;
        st[t] = false;
        for (int i = h[t]; ~i; i = ne[i]) {
            int v = e[i];
            if (dist[v] < dist[t] + w[i]) {
                dist[v] = dist[t] + w[i];
                cnt[v] = cnt[t] + 1;
                if (cnt[v] >= 25) return false;

                if (!st[v]) {
                    q[tt++] = v;
                    if (tt == N) tt = 0;
                    st[v] = true;
                }
            }
        }
    }

    return true;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        for (int i = 1; i <= 24; i++) cin >> r[i];
        cin >> n;
        memset(num, 0, sizeof num);
        for (int i = 0; i < n; i++) {
            int t;
            cin >> t;
            num[t + 1]++;
        }

        bool success = false;
        for (int i = 0; i <= 1000; i++) 
            if (spfa(i)) {
                cout << i << endl;
                success = true;
                break;
            }

        if (!success) puts("No Solution");
    }

    return 0;
}