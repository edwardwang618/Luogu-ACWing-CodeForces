#include <iostream>
using namespace std;

const int N = 110;
int n;
int a[N];
int f1[N], f2[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int i = 1; i <= n; i++) {
        f1[i] = 1;
        for (int j = 1; j < i; j++)
            if (a[i] > a[j])
                f1[i] = max(f1[i], 1 + f1[j]);
    }

    for (int i = n; i >= 1; i--) {
        f2[i] = 1;
        for (int j = i + 1; j <= n; j++)
            if (a[i] > a[j])
                f2[i] = max(f2[i], 1 + f2[j]);
    }

    int res = 0;
    for (int i = 1; i <= n; i++)
        res = max(res, f1[i] + f2[i] - 1);

    cout << n - res << endl;

    return 0;
}