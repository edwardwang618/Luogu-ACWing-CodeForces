#include <iostream>
#include <algorithm>
using namespace std;

const int N = 50;
int n, m, k;
int a[N];
int weights[1 << 24], cnt;
int res;

void dfs1(int u, int s) {
    if (u == k) {
        weights[cnt++] = s;
        return;
    }   

    if ((long) s + a[u] <= m) dfs1(u + 1, s + a[u]);
    dfs1(u + 1, s);
}

void dfs2 (int u, int s) {
    if (u == n) {
        int l = 0, r = cnt - 1;
        while(l < r) {
            int mid = (l + r + 1) >> 1;
            if ((long) weights[mid] + s <= m) l = mid;
            else r = mid - 1;
        }

        if ((long) weights[l] + s <= m) res = max(res, weights[l] + s);
        return;
    }

    if ((long) s + a[u] <= m) dfs2(u + 1, s + a[u]);
    dfs2(u + 1, s);
}

int main() {
    cin >> m >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a, a + n, greater<int>());

    k = n / 2 + 2;
    dfs1(0, 0);

    sort(weights, weights + cnt);
    cnt = unique(weights, weights + cnt) - weights;

    dfs2(k, 0);

    cout << res << endl;

    return 0;
}