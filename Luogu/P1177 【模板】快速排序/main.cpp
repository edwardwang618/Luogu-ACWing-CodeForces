#include <iostream>
using namespace std;

const int N = 1e6+10;
int n;
int q[N];

void quick_sort(int q[], int l, int r) {
    if (l >= r) return;

    int x = q[l + (r - l >> 1)], i = l, j = r;
    while (i <= j) {
        while (q[i] < x) i++;
        while (q[j] > x) j--;
        if (i <= j) {
            swap(q[i], q[j]);
            i++, j--;
        }
    }

    quick_sort(q, l, j);
    quick_sort(q, i, r);
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &q[i]);

    quick_sort(q, 0, n - 1);
    for (int i = 0; i < n; ++i) printf("%d ", q[i]);

    return 0;
}
