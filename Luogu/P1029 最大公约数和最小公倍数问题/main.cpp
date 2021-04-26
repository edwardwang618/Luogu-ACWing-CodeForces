#include <iostream>
#include <cmath>
using namespace std;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
    long x, y;
    cin >> x >> y;

    int res = 0;
    if (x == y) res = 1;
    else {
        for (long i = x; i <= sqrt(x * y); i += x) {
            if (x * y % i) continue;
            long a = i, b = x * y / i;
            if (gcd(a, b) == x) res++;
        }

        res *= 2;
    }

    cout << res << endl;

    return 0;
}