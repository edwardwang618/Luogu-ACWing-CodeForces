#include <iostream>
using namespace std;

const int mod = 1e9 + 7;

int fast_pow(int a, int k, int p) {
    int res = 1;
    while (k) {
        if (k & 1) res = (long) res * a % p;
        a = (long) a * a % p;
        k >>= 1;
    }

    return res;
}

int main() {
    int n;
    cin >> n;

    int a = 2 * n, b = n;
    int res = 1;

    for (int i = a; i > a - b; i--) res = (long) res * i % mod;
    for (int i = 1; i <= b; i++) res = (long) res * fast_pow(i, mod - 2, mod) % mod;

    res = (long) res * fast_pow(n + 1, mod - 2, mod) % mod;
    cout << res << endl;

    return 0;
}