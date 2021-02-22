#include <iostream>
using namespace std;

long exgcd(long a, long b, long &x, long &y) {
    if (!b) {
        x = 1, y = 0;
        return a;
    }

    long d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

int main() {
    int n;
    cin >> n;
    
    bool has_answer = true;
    long a1, m1;

    cin >> a1 >> m1;
    for (int i = 0; i < n - 1; i++) {
        long a2, m2;
        cin >> a2 >> m2;

        long k1, k2;
        long d = exgcd(a1, a2, k1, k2);
        if ((m1 - m2) % d) {
            has_answer = false;
            break;
        }

        k1 *= (m2 - m1) / d;
        long t = a2 / d;
        k1 = (k1 % t + t) % t;

        m1 += a1 * k1;
        a1 = abs(a1 / d * a2);
    }

    if (has_answer) cout << (m1 % a1 + a1) % a1 << endl;
    else cout << -1 << endl;

    return 0;
}