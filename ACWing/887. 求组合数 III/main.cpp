#include <iostream>
using namespace std;

int p;

int fast_pow(int a, int k) {
    int res = 1;
    while (k) {
        if (k & 1) res = (long) res * a % p;
        a = (long) a * a % p;
        k >>= 1;
    }

    return res;
}

int C(int a, int b) {
    int res = 1;
    for (int i = 1, j = a; i <= b; i++, j--) {
        res = (long) res * j % p;
        res = (long) res * fast_pow(i, p - 2) % p;
    }

    return res;
}

int lucas(long a, long b) {
    if (a < p && b < p) return C(a, b);
    return (long) C(a % p, b % p) * lucas(a / p, b / p) % p;
}

int main() {
    int n;
    cin >> n;

    while (n--) {
        long a, b;
        cin >> a >> b >> p;
        cout << lucas(a, b) << endl;
    }

    return 0;
}