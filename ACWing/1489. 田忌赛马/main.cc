#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1010;
int n;
int a[N], b[N];

int main() {   
    while (cin >> n, n) {
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(a, a + n);
        for (int i = 0; i < n; i++) cin >> b[i];
        sort(b, b + n);

        int res = 0;
        for (int la = 0, ra = n - 1, lb = 0, rb = n - 1; la <= ra;) {
            if (b[rb] > a[ra]) {
                res -= 200;
                la++, rb--;
            } else if (b[rb] < a[ra]) {
                res += 200;
                ra--, rb--;
            } else {
                if (b[lb] < a[la]) {
                    res += 200;
                    la++, lb++;
                } else {
                    if (a[la] < b[rb]) res -= 200;
                    la++, rb--;
                }
            }
        }

        cout << res << endl;
    }

    return 0;
}