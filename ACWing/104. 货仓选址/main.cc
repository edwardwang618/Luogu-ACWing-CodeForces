#include <iostream>
using namespace std;

const int N = 100010;
int n;
int a[N];

int quick_select(int l, int r, int idx) {
    if (l == r) return a[l];
    int i = l, j = r;
    int m = a[l + (r - l >> 1)];
    while (i <= j) {
        while (a[i] < m) i++;
        while (a[j] > m) j--;
        if (i <= j) swap(a[i++], a[j--]);
    }
    
    if (idx <= j) return quick_select(l, j, idx);
    if (idx >= i) return quick_select(i, r, idx);
    return a[idx];
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int res = 0;
    int x = quick_select(0, n - 1, n / 2);
    for (int i = 0; i < n; i++) res += abs(a[i] - x);

    printf("%d\n", res);
}