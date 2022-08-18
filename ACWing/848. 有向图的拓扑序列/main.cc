#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int N = 100010;
int n, m;
int h[N], e[N], ne[N], idx;
int d[N];
bool vis[N];
int res[N], cnt;

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

bool bfs() {
    queue<int> q;
    for (int i = 1; i <= n; i++) 
        if (!d[i]) q.push(i);

    while (!q.empty()) {
        int t = q.front(); q.pop();
        res[++cnt] = t;
        for (int i = h[t]; ~i; i = ne[i]) {
            int j = e[i];
            d[j]--;
            if (!d[j]) q.push(j);
        }
    }

    return cnt == n;
}

int main() {
    memset(h, -1, sizeof h);
    cin >> n >> m;
    while (m--) {
        int a, b;
        cin >> a >> b;
        add(a, b);
        d[b]++;
    }

    if (!bfs()) puts("-1");
    else for (int i = 1; i <= n; i++) cout << res[i] << ' ';

    return 0;
}