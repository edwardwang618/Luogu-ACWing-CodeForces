#include <iostream>
using namespace std;

const int N = 110;
int n;
int a[N], tmp[N], id[N];
int cnt[N];

void merge_sort(int l, int r) {
    if (l >= r) return;
    int mid = l + (r - l >> 1);
    merge_sort(l, mid); merge_sort(mid + 1, r);
    
    int i = l, j = mid + 1, idx = l;
    while (i <= mid && j <= r)
        if (a[id[i]] < a[id[j]]) tmp[idx++] = id[i++];
        else {
            cnt[id[j]] += i - l;
            tmp[idx++] = id[j++];
        }

    while (i <= mid) tmp[idx++] = id[i++];
    while (j <= r) {
        cnt[id[j]] += i - l;
        tmp[idx++] = id[j++];
    }

    for (int k = l; k <= r; k++) id[k] = tmp[k];
}


int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        id[i] = i;
    }

    merge_sort(1, n);
    for (int i = 1; i <= n; i++) printf("%d ", cnt[i]);
    puts("");

    return 0;
}