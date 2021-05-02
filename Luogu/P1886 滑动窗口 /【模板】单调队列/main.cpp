#include <iostream>
using namespace std;

const int N = 1e6 + 10;
int n, k;
int a[N], q[N];
int res[N];

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];

    int hh = 0, tt = 0;
    for (int i = 1; i <= n; i++) {
        if (hh < tt && q[hh] <= i - k) hh++;
        while (hh < tt && a[q[tt - 1]] >= a[i]) tt--;
        q[tt++] = i;

        if (i >= k) res[i - k + 1] = a[q[hh]];
    }

    for (int i = 1; i <= n - k + 1; i++) cout << res[i] << ' ';
    cout << endl;

    hh = tt = 0;
    for (int i = 1; i <= n; i++) {
        if (hh < tt && q[hh] <= i - k) hh++;
        while (hh < tt && a[q[tt - 1]] <= a[i]) tt--;
        q[tt++] = i;

        if (i >= k) res[i - k + 1] = a[q[hh]];
    }

    for (int i = 1; i <= n - k + 1; i++) cout << res[i] << ' ';
    cout << endl;

    return 0;
}