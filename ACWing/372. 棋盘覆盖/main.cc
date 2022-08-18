#include <iostream>
#include <cstring>

using namespace std;

const int N = 1e4 + 10, M = 2 * N * N, d[] = {1, 0, -1, 0, 1};
int n, m;
int h[N], e[M], ne[M], idx;
bool forb[N];
int match[N];
bool st[N];

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int get_pos(int x, int y) {
    return (x - 1) * n + y;
}

bool dfs(int u) {
    if (forb[u]) return false;
    
    for (int i = h[u]; ~i; i = ne[i]) {
        int j = e[i];
        if (st[j]) continue;
        if (forb[j]) continue;

        st[j] = true;
        if (!match[j] || dfs(match[j])) {
            match[j] = u;
            return true;
        }
    }

    return false;
}

int main() {
    cin >> n >> m;
    while (m--) {
        int x, y;
        cin >> x >> y;
        forb[get_pos(x, y)] = true;
    }

    memset(h, -1, sizeof h);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if ((i + j) % 2 == 0) {
                for (int k = 0; k < 4; ++k) {
                    int ni = i + d[k], nj = j + d[k + 1];
                    if (1 <= ni && ni <= n && 1 <= nj && nj <= n)
                        add(get_pos(i, j), get_pos(ni, nj));
                }
            }

    int res = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if ((i + j) % 2 == 0) {
                memset(st, 0, sizeof st);
                if (dfs(get_pos(i, j))) res++;
            }

    cout << res << endl;
    return 0;
}