#include <iostream>
using namespace std;

inline long f(long x, long y) {
    if (!x && !y) return 0;
    if (x == 1 && y == 0) return 3;
    if (x == 2 && y == 2) return 4;
    if (y <= x - y) {
        if (x % 2 == 0) return x / 2 + (x / 2 - y) % 2;
        else return (x + 1) / 2 + ((x + 1) / 2 - (y + 1)) % 2;
    }
    
    long d = (2 * y - x) / 3;
    if (!d) d = 1;
    x += d, y -= d;
    return f(x, y);
}

int main() {
    long x, y, a, b;
    scanf("%ld%ld%ld%ld", &x, &y, &a, &b);
    long c = abs(x - a), d = abs(y - b);
    if (c < d) swap(c, d);
    printf("%ld\n", abs(f(c, d)));
    return 0;
}