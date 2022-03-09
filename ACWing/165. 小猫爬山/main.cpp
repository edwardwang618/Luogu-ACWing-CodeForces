#include <iostream>
#include <algorithm>
using namespace std;

const int N = 20;
int n, w;
int a[N], sum[N];
int res;

void dfs(int u, int k) {
    if (k >= res) return;

    if (u == n) {
        res = k;
        return;
    }

    for (int i = 0; i < k; i++) {
        if (sum[i] + a[u] <= w) {
            sum[i] += a[u];
            dfs(u + 1, k);
            sum[i] -= a[u];
        }
    }
        
    sum[k] = a[u];
    dfs(u + 1, k + 1);
}

int main() {
    cin >> n >> w;
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a, a + n, greater<int>());

    res = n;

    dfs(0, 0);
    cout << res << endl;

    return 0;
}