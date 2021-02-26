#include <iostream>
using namespace std;

const int N = 100010;
int a[N];

int quick_select(int l, int r, int idx) {
    int i = l, j = r;
    int m = a[l + (r - l >> 1)];
    do
    {
        while (a[i] < m) i++;
        while (a[j] > m) j--;
        if (i <= j) {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    } while (i <= j);
    
    if (idx <= j) return quick_select(l, j, idx);
    else if (idx >= i) return quick_select(i, r, idx);
    else return a[idx];
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    int res = 0;
    int x = quick_select(0, n - 1, n / 2);
    for (int i = 0; i < n; i++) res += abs(a[i] - x);

    cout << res << endl;

    return 0;
}