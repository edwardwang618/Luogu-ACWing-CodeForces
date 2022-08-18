#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 2e5 + 10;
int n, k;
int a[N];

bool check(int mid) {
    int c = 0;
    for (int i = n >> 1; i < n; i++) {
        c += max(0, mid - a[i]);
        if (c > k) return false;
    }

    return true;
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a, a + n);
    int l = a[0], r = a[n >> 1] + k;
    while (l < r) {
        int mid = l + (r - l + 1 >> 1);
        if (check(mid)) l = mid;
        else r = mid - 1;
    }
    
    cout << l << endl;

    return 0;
}