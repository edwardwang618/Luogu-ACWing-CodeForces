#include <iostream>
#include <cstring>
using namespace std;

const int N = 6010;
int h[N], e[N], ne[N], idx;
int f[N][2];
int a[N];
bool has_father[N];

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int dfs(int u) {
    f[u][1] = a[u];
    for (int i = h[u]; i != -1; i = ne[i]) {
        int j = e[i];
        dfs(j);
        f[u][0] += max(f[j][0], f[j][1]);
        f[u][1] += f[j][0];
    }
}

int main() {
    memset(h, -1, sizeof h);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 1; i <= n - 1; i++) {
        int l, k;
        cin >> l >> k;
        add(k, l);
        has_father[l] = true;
    }

    int root = 1;
    while (has_father[root]) root++;

    dfs(root);

    cout << max(f[root][0], f[root][1]) << endl;

    return 0;
}