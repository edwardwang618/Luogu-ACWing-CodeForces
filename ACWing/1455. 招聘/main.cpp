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
        for (int i = 1; i <= m; i++) cin >> a[i];

        int res = 0;
        for (int i = 1; i <= n; i++) 
            res = (res + a[1 + (n - i) % m]) % i;

        cout << res << endl;
    }

    return 0;
}