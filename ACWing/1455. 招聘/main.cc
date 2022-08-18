#include <iostream>
using namespace std;

const int N = 1e7 + 10;
int a[N], f[N];
int n, m;

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        for (int i = 1; i <= m; i++) scanf("%d", &a[i]);

        f[1] = 0;
        for (int i = 2; i <= n; i++) 
            f[i] = (f[i - 1] + a[(n - i) % m + 1]) % i;

        printf("%d\n", f[n]);
    }

    return 0;
}