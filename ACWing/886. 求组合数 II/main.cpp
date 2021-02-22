#include <iostream>
using namespace std;

const int N = 100010, mod = 1e9 + 7;

int fact[N], infact[N];

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
    fact[0] = infact[0] = 1;
    for (int i = 1; i < N; i++) {
        fact[i] = (long) fact[i - 1] * i % mod;
        infact[i] = (long) infact[i - 1] * fast_pow(i, mod - 2, mod) % mod;
    }

    int n;
    cin >> n;
    while (n--) {
        int a, b;
        cin >> a >> b;
        cout << ((long) fact[a] * infact[b] % mod * infact[a - b] % mod) << endl;
    }

    return 0;
}