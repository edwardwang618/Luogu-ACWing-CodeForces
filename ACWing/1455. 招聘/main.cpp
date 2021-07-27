#include <iostream>
#include <cstring>
using namespace std;

const int N = 1e3 + 10;
int a[N];
int n, m;

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        for (int i = 0; i < m; ++ i) cin >> a[i];

        int res = 0;
        for (int i = 2; i <= n; ++ i) 
            res = (res + a[(n - i) % m]) % i;

        cout << res << endl;
    }

    return 0;
}