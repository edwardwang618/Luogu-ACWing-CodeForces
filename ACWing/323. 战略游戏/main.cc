#include <iostream>
#include <cstring>
using namespace std;

const int N = 1510;

int n;
int h[N], e[N], ne[N], idx;
int f[N][2];
bool is_root[N];

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void dfs(int u) {
    int c0 = 0, c1 = 1;
    for (int i = h[u]; ~i; i = ne[i]) {
        int j = e[i];
        dfs(j);

        c0 += f[j][1];
        c1 += min(f[j][0], f[j][1]);
    }

    f[u][0] = c0;
    f[u][1] = c1;
}

int main() {
    while (scanf("%d", &n) != -1) {
        memset(h, -1, sizeof h);
        memset(is_root, true, sizeof is_root);
        memset(f, 0, sizeof f);
        idx = 0;

        for (int i = 0; i < n; i++) {
            int id, cnt;
            scanf("%d:(%d)", &id, &cnt);
            for (int j = 0; j < cnt; j++) {
                int a;
                cin >> a;
                add(id, a);
                is_root[a] = false;
            }
        }

        for (int i = 0; i < n; i++)
            if (is_root[i]) {
                dfs(i);
                cout << min(f[i][0], f[i][1]) << endl;
                break;
            }
    }

    return 0;
}