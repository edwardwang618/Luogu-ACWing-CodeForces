#include <iostream>
#include <cstring>
using namespace std;

const int N = 110;
int a[N];
int f[N];

int main() {
    int k;
    cin >> k;

    while (k--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];

        int res = 0;
        for (int i = 1; i <= n; i++) {
            f[i] = 1;
            for (int j = 1; j < i; j++)
                if (a[i] > a[j])
                    f[i] = max(f[i], 1 + f[j]);
            res = max(res, f[i]);
        }
        
        for (int i = n; i >= 1; i--) {
            f[i] = 1;
            for (int j = i + 1; j <= n; j++)
                if (a[i] > a[j])
                    f[i] = max(f[i], 1 + f[j]);
            res = max(res, f[i]);
        }

        cout << res << endl;
    }

    return 0;
}