#include <iostream>
using namespace std;

const int N = 11;
int n;
int a[N];
int g[N][N];
int res = N;
bool st[N];

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

bool check(int u, int gc, int idx) {
    for (int i = 0; i < gc; i++)
        if (gcd(a[g[u][i]], a[idx]) > 1) return false;

    return true;
}

void dfs(int u, int gc, int tc, int start) {
    if (u >= res) return;

    if (tc == n) {
        res = u;
        return;
    }

    bool added = false;
    for (int i = start; i < n; i++) {
        if (!st[i] && check(u, gc, i)) {
            st[i] = true;
            g[u][gc] = i;

            dfs(u, gc + 1, tc + 1, i + 1);

            st[i] = false;
            added = true;
        }
    }

    if (!added) dfs(u + 1, 0, tc, 0);
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    dfs(1, 0, 0, 0);

    cout << res << endl;

    return 0;
}