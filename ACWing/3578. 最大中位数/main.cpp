#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 2e5 + 10;
int n, k;
long a[N];

bool check(long mid) {
    long c = 0;
    for (int i = n >> 1; i < n; i++) {
        c += max(0L, mid - a[i]);
        if (c > k) return false;
    }

    return true;
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a, a + n);
    long l = a[0], r = a[n >> 1] + k;
    while (l < r) {
        long mid = l + (r - l + 1 >> 1);
        if (check(mid)) l = mid;
        else r = mid - 1;
    }
    
    cout << l << endl;

    return 0;
}