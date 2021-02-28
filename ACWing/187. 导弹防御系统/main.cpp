#include <iostream>
using namespace std;

const int N = 35;
int n;
int a[N];
int up[N], down[N];
int res;

void dfs(int u, int su, int sd) {
    if (su + sd >= res) return;
    if (u == n) {
        res = su + sd;
        return;
    }

    int l = 0, r = su - 1;
    while (l < r) {
        int m = l + (r - l >> 1);
        if (up[m] < a[u]) r = m;
        else l = m + 1;
    }

    if (l > r || up[l] >= a[u]) {
        up[su++] = a[u]; dfs(u + 1, su, sd); su--;
    } else {
        int t = up[l]; up[l] = a[u]; dfs(u + 1, su, sd); up[l] = t;
    }

    l = 0, r = sd - 1;
    while (l < r) {
        int m = l + (r - l >> 1);
        if (down[m] > a[u]) r = m;
        else l = m + 1;
    }

    if (l > r || down[l] <= a[u]) {
        down[sd++] = a[u]; dfs(u + 1, su, sd); sd--;
    } else {
        int t = down[l]; down[l] = a[u]; dfs(u + 1, su, sd); down[l] = t;
    }
}

int main() {
    while (cin >> n, n) {
        for (int i = 0; i < n; i++) cin >> a[i];

        res = n;
        dfs(0, 0, 0);

        cout << res << endl;
    }

    return 0;
}