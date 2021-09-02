#include <iostream>
using namespace std;

const int N = 1010;
int a[N];
int n, l, r;

void sort(int a[], int l, int r) {
    if (l >= r) return;
    static int tmp[N] = {0};
    int mid = l + (r - l >> 1);
    sort(a, l, mid), sort(a, mid + 1, r);
    int i = l, j = mid + 1, idx = l;
    while (i <= mid && j <= r) 
        if (a[i] <= a[j]) tmp[idx++] = a[i++];
        else tmp[idx++] = a[j++];
    
    while (i <= mid) tmp[idx++] = a[i++];
    while (j <= r) tmp[idx++] = a[j++];
    for (int k = l; k <= r; k++) a[k] = tmp[k];
}

int main() {
    scanf("%d%d%d", &n, &l, &r);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    sort(a, l, r);
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    puts("");

    return 0;
}