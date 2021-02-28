#include <iostream>
#include <algorithm>
using namespace std;

typedef pair<int, int> PII;

const int N = 5010;
PII a[N];
int f[N];
int n;

int main() {
    cin >> n;

    for (int i = 1; i <= n; i++) cin >> a[i].first >> a[i].second;

    sort(a + 1, a + n + 1);

    int res = 0;
    for (int i = 1; i <= n; i++) {
        f[i] = 1;
        for (int j = 1; j < i; j++)
            if (a[i].second > a[j].second)
                f[i] = max(f[i], 1 + f[j]);

        res = max(res, f[i]);
    }

    cout << res << endl;

    return 0;
}