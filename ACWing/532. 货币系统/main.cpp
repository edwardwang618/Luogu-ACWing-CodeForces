#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 110, M = 25010;
int n;
int a[N];
bool f[M];

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        sort(a + 1, a + n + 1);

        memset(f, 0, sizeof f);
        f[0] = true;

        int res = 0;
        for (int i = 1; i <= n; i++) {
            if (!f[a[i]]) res++;
            for (int j = a[i]; j <= a[n]; j++)
                f[j] |= f[j - a[i]];
        }

        cout << res << endl;
    }

    return 0;
}