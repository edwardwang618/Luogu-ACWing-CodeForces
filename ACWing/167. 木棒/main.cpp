#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 70;
int n;
int a[N], len, sum;
bool st[N];

bool dfs(int u, int l, int start) {
    if (u * len == sum) return true;
    if (l == len) return dfs(u + 1, 0, 0);

    for (int i = start; i < n; i++) {
        if (st[i]) continue;
        if (l + a[i] > len) continue;
        if (i > start && !st[i - 1] && a[i] == a[i - 1]) continue;

        st[i] = true;
        if (dfs(u, l + a[i], i + 1)) return true;
        st[i] = false;

        if (!l || l + a[i] == len) return false;
    }

    return false;
}

int main() {
    while (cin >> n, n) {
        sum = len = 0;
        memset(st, 0, sizeof st);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            sum += a[i];
        }

        sort(a, a + n, greater<int>());
        for (len = a[0]; len <= sum; len++)
            if (sum % len == 0 && dfs(0, 0, 0)) {
                printf("%d\n", len);
                break;
            }
    }

    return 0;
}