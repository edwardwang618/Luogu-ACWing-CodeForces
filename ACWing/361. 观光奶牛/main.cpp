#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int N = 1010, M = 5010;
int n, m;
int wf[N];
int h[N], e[M], wt[M], ne[M], idx;
double dist[N];
int cnt[N];
bool st[N];

void add(int a, int b, int c) {
    e[idx] = b, ne[idx] = h[a], wt[idx] = c, h[a] = idx++;
}

bool check(double mi) {
    memset(dist, 0, sizeof dist);
    memset(cnt, 0, sizeof cnt);
    memset(st, 0, sizeof st);

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
            if (dist[j] < dist[t] + wf[t] - mi * wt[i]) {
                dist[j] = dist[t] + wf[t] - mi * wt[i];
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
    cin >> n >> m;
    memset(h, -1, sizeof h);

    for (int i = 1; i <= n; i++) cin >> wf[i];

    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }
    
    double l = 0, r = 1000;
    while (l + 1e-4 < r) {
        double mi = (l + r) / 2;
        if (check(mi)) l = mi;
        else r = mi;
    }
    
    printf("%.2lf\n", l);

    return 0;
}