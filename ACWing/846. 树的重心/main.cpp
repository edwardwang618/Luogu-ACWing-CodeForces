#include <iostream>
#include <cstring>
using namespace std;

const int N = 100010, M = 2 * N;
int res = N;
int n;
int h[N], e[M], ne[M], idx;
bool vis[N];

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int dfs(int u) {
    vis[u] = true;

    int cnt = 1, cur_res = 0;
    for (int i = h[u]; i != -1; i = ne[i]) {
        int j = e[i];
        if (!vis[j]) {
            int s = dfs(j);
            cur_res = max(cur_res, s);
            cnt += s;
        }
    }

    cur_res = max(cur_res, n - cnt);
    res = min(res, cur_res);
    return cnt;
}

int main() {
    cin >> n;
    memset(h, -1, sizeof h);

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        add(a, b), add(b, a);
    }

    dfs(1);

    cout << res << endl;
    return 0;
}