#include <iostream>
using namespace std;

const int N = 100010;
int n, k;
int a[N];

int quick_select(int l, int r, int idx) {
    int i = l, j = r;
    int piv = a[l + (r - l >> 1)];
    while (i <= j) {
        while (a[i] < piv) i++;
        while (a[j] > piv) j--;
        if (i <= j) swap(a[i++], a[j--]);
    }

    if (idx <= j) return quick_select(l, j, idx);
    if (idx >= i) return quick_select(i, r, idx);
    return a[idx];
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    cout << quick_select(0, n - 1, k - 1) << endl;
    return 0;
}