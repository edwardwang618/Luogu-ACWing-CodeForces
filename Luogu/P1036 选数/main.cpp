#include <iostream>
#include <cmath>
using namespace std;

const int N = 25;
int a[N], n, k;
int res;

bool check(int x) {
    for (int i = 2; i <= sqrt(x); i++) if (x % i == 0) return false;
    return true;
}

void dfs(int u, int cnt, int sum) {
    if (cnt == k) {
        if (check(sum)) res++;
        return;
    }

    if (u == n + 1) return;

    for (int i = u; i + k - cnt - 1 <= n; i++) {
        sum += a[i];
        dfs(i + 1, cnt + 1, sum);
        sum -= a[i];
    }
}

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];

    dfs(1, 0, 0);
    cout << res << endl;

    return 0;
}