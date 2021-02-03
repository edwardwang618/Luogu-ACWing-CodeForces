#include <iostream>
#include <algorithm>
using namespace std;

const int N = 10010;

int n, m;
int a[N];

int main() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) cin >> a[i];

    while (m--) {
        int k = n;
        while (a[k - 1] > a[k]) k--;
        
        int l = k, r = n;
        while (l < r) {
            int m = l + (r - l + 1 >> 1);
            if (a[m] > a[k - 1]) {
                l = m;
            } else {
                r = m - 1;
            }
        }

        swap(a[k - 1], a[l]);
        reverse(a + k, a + n + 1);
    }

    for (int i = 1; i <= n; i++) cout << a[i] << ' ';
    cout << endl;

    return 0;
}