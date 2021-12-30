#include <iostream>
#include <cmath>
using namespace std;

long f(long x, long y) {
    if (x == 1 && y == 0) return 3;
    if (x == 2 && y == 2) return 4;

    long delta = x - y;
    if (y > delta) return delta - 2 * floor((double) (delta - y) / 3.0);
    else return delta - 2 * floor((double) (delta - y) / 4.0);
}

int main() {
    long x, y, a, b;
    scanf("%ld%ld%ld%ld", &x, &y, &a, &b);
    long c = abs(x - a), d = abs(y - b);
    if (c < d) swap(c, d);
    printf("%ld\n", abs(f(c, d)));
    return 0;
}