#include <iostream>
using namespace std;

const int N = 100010;
int n;
int a[N], tmp[N];

long merge_sort(int l, int r) {
    if (l >= r) {
        return 0;
    }

    int m = l + (r - l >> 1);
    long res = 0;
    res += merge_sort(l, m);
    res += merge_sort(m + 1, r);

    int i = l, j = m + 1, idx = l;
    while (i <= m && j <= r) {
        if (a[i] > a[j]) {
            res += m - i + 1;
            tmp[idx++] = a[j++];
        } else {
            tmp[idx++] = a[i++];
        }
    }

    while (i <= m) tmp[idx++] = a[i++];
    while (j <= r) tmp[idx++] = a[j++];

    for (i = l; i <= r; i++) a[i] = tmp[i];

    return res;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    cout << merge_sort(0, n - 1) << endl;

    return 0;
}