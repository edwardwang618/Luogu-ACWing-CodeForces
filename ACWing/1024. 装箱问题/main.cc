#include <iostream>
using namespace std;

const int N = 20020, M = 31;
int a[M];
bool f[N];
int n;

int main() {
    int V;
    cin >> V >> n;

    for (int i = 1; i <= n; i++) cin >> a[i];

    int res = V;
    f[0] = true;
    for (int i = 1; i <= n; i++)
        for (int j = V; j >= a[i]; j--) {
            f[j] |= f[j - a[i]];
            if (f[j]) res = min(res, V - j);
        }

    cout << res << endl;

    return 0;
}