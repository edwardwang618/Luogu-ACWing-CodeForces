#include <iostream>
using namespace std;

const int N = 1e3 + 10;
int a[N];
int n, m;

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        for (int i = 1; i <= m; i++) scanf("%d", &a[i]);

        int res = 0;
        for (int i = 2; i <= n; i++) 
            res = (res + a[(n - i) % m + 1]) % i;

        printf("%d\n", res);
    }

    return 0;
}