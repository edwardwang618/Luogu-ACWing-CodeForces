#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int N = 2510;
int n, m;
int s, e, dis[N];
bool st[N];
int g[N][N];

void spfa() {
    memset(dis, 0x3f, sizeof dis);
    dis[s] = 0;
    
    queue<int> q;
    q.push(s);

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
    cin >> s >> e;

    memset(g, 0x3f, sizeof g);

    for (int i = 0; i < m; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        g[a][b] = g[b][a] = min(g[a][b], c);
    }

    spfa();

    cout << dis[e] << endl;

    return 0;
}