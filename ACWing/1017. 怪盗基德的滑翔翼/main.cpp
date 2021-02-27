#include <iostream>
#include <cstring>
using namespace std;

const int N = 110;
int a[N];
int f1[N], f2[N];

int main() {
    int k;
    cin >> k;

    while (k--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];

        memset(f1, 0, sizeof f1);
        memset(f2, 0, sizeof f2);

        f1[1] = 1;
        for (int i = 2; i <= n; i++) {
            f1[i] = 1;
            for (int j = 1; j < i; j++)
                if (a[i] > a[j])
                    f1[i] = max(f1[i], 1 + f1[j]);
        }
        
        f2[n] = 1;
        for (int i = n - 1; i >= 1; i--) {
            f2[i] = 1;
            for (int j = i + 1; j <= n; j++)
                if (a[i] > a[j])
                    f2[i] = max(f2[i], 1 + f2[j]);
        }

        int res = 0;
        for (int i = 1; i <= n; i++) {
            res = max(res, f1[i]);
            res = max(res, f2[i]);
        }

        cout << res << endl;
    }

    return 0;
}