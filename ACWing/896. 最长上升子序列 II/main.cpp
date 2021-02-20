#include <iostream>
using namespace std;

const int N = 100010;
int n;
int a[N], f[N];

int binary_search(int r, int t) {
    if (r < 0) return -1;

    int l = 0;
    while (l < r) {
        int m = l + (r - l >> 1);
        if (f[m] >= t) r = m;
        else l = m + 1;
    }

    return f[l] >= t ? l : -1;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    int idx = 0;
    for (int i = 0; i < n; i++) {
        int pos = binary_search(idx - 1, a[i]);
        if (pos == -1) f[idx++] = a[i];
        else f[pos] = a[i];
    }

    cout << idx << endl;

    return 0;
}