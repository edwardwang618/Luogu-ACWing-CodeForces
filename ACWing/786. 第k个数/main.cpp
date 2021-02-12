#include <iostream>
using namespace std;

const int N = 100000;
int n, k;
int a[N];

int part(int l, int r, int idx) {
    int i = l, j = r;
    int m = a[l + (r - l >> 1)];
    do {
        while (a[i] < m) i++;
        while (a[j] > m) j--;
        if (i <= j) {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    } while (i <= j);

    if (idx <= j) return part(l, j, idx);
    else if (idx >= i) return part(i, r, idx);
    else return a[idx];
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    cout << part(0, n - 1, k - 1) << endl;
    return 0;
}