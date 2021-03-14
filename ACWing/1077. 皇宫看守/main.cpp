#include <iostream>
#include <cstring>
using namespace std;

const int N = 1510;
int n;
int h[N], e[N], ne[N], w[N], idx;
int f[N][3];
bool st[N];

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void dfs(int u) {
    f[u][2] = w[u];
    for (int i = h[u]; ~i; i = ne[i]) {
        int j = e[i];

        dfs(j);

        f[u][0] += min(f[j][1], f[j][2]);
        f[u][2] += min(min(f[j][0], f[j][1]), f[j][2]);
    }

    f[u][1] = 0x3f3f3f3f;
    for (int i = h[u]; ~i; i = ne[i]) {
        int j = e[i];
        f[u][1] = min(f[u][1], f[j][2] + f[u][0] - min(f[j][1], f[j][2]));
    }
}

int main() {
    cin >> n;
    memset(h, -1, sizeof h);

    for (int i = 1; i <= n; i++) {
        int id, cost, cnt;
        cin >> id >> cost >> cnt;
        w[id] = cost;
        while (cnt--) {
            int v;
            cin >> v;
            add(id, v);
            st[v] = true;
        }
    }

    for (int i = 1; i <= n; i++) 
        if (!st[i]) {
            dfs(i);
            cout << min(f[i][1], f[i][2]) << endl;
        }

    return 0;
}