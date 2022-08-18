#include <iostream>
using namespace std;

const int N = 100010;
int n;
int a[N], tmp[N];

void merge_sort(int l, int r) {
    if (l >= r) return;

    int m = l + (r - l >> 1);
    merge_sort(l, m);
    merge_sort(m + 1, r);

    int idx = 0, i = l, j = m + 1;
    while (i <= m && j <= r) {
        if (a[i] <= a[j]) tmp[idx++] = a[i++];
        else tmp[idx++] = a[j++];
    }

    while (i <= m) tmp[idx++] = a[i++];
    while (j <= r) tmp[idx++] = a[j++];

    for (i = l, j = 0; i <= r; i++, j++) a[i] = tmp[j];
}


int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    merge_sort(0, n - 1);
    for (int i = 0; i < n; i++) printf("%d ", a[i]);

    return 0;
}