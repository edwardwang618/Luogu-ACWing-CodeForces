#include <iostream>
using namespace std;

const int N = 1e4 + 10;
int n;
int a[N], tmp[N];
int res = 0;  

void merge(int l, int mid, int r) {
    int i = l, j = mid + 1;
    int idx = l;
    while (i <= mid && j <= r)
        if (a[i] <= a[j]) tmp[idx++] = a[i++];
        else { 
            // 此时a[i]直到a[mid]都与a[j]产生了逆序对
            res += mid - i + 1; 
            tmp[idx++] = a[j++];
        }

    while (i <= mid) tmp[idx++] = a[i++];
    while (j <= r) tmp[idx++] = a[j++];

    for (int k = l; k <= r; k++) a[k] = tmp[k];
}

void merge_sort(int l, int r) {
    if (l >= r) return;

    int mid = l + (r - l >> 1);
    merge_sort(l, mid), merge_sort(mid + 1, r);
    merge(l, mid, r);
}

int main() {
    cin >> n;
    for (int i = 0; i < N; ++i) cin >> a[i];

    merge_sort(0, n - 1);

    cout << res << endl;

    return 0;
}