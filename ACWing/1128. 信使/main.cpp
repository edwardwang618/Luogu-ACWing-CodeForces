#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int N = 110;
int n, m;
int g[N][N], dis[N];
bool st[N];

void spfa() {
    memset(dis, 0x3f, sizeof dis);
    dis[1] = 0;

    queue<int> q;
    q.push(1);

    while (q.size()) {
        int t = q.front();
        q.pop();
        st[t] = false;

        for (int i = 1; i <= n; i++) {
            if (dis[i] > dis[t] + g[t][i]) {
                dis[i] = dis[t] + g[t][i];
                if (!st[i]) {
                    q.push(i);
                    st[i] = true;
                }
            }
        }
    }
}

int main() {
    cin >> n >> m;

    memset(g, 0x3f, sizeof g);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a][b] = g[b][a] = min(g[a][b], c);
    }

    spfa();

    int res = 0;
    for (int i = 1; i <= n; i++)
        res = max(res, dis[i]);

    cout << (res == 0x3f3f3f3f ? -1 : res) << endl;

    return 0;
}