#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e5 + 10, MOD = 1e8 - 3;
int n;

struct Pair {
    int x, id;
    bool operator<(const Pair &p) const {
        return x <= p.x;
    }
} a[N], b[N];

int c[N], tmp[N];
int res;

void merge_sort(int l, int r) {
    if (l >= r) return;
    int mid = l + r >> 1;
    merge_sort(l, mid);
    merge_sort(mid + 1, r);

    int i = l, j = mid + 1, idx = l;
    while (i <= mid && j <= r) {
        if (c[i] <= c[j]) tmp[idx++] = c[i++];
        else {
            res = (res + mid - i + 1) % MOD;
            tmp[idx++] = c[j++];
        }
    }

    while (i <= mid) tmp[idx++] = c[i++];
    while (j <= r) tmp[idx++] = c[j++];
    for (int k = l; k <= r; k++) c[k] = tmp[k];
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i].x);
        a[i].id = i;
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &b[i].x);
        b[i].id = i;
    }

    sort(a + 1, a + 1 + n);
    sort(b + 1, b + 1 + n);

    for (int i = 1; i <= n; i++) c[a[i].id] = b[i].id;
    merge_sort(1, n);
    printf("%d\n", res);

    return 0;
}