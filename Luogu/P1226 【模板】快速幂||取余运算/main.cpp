#include <iostream>
using namespace std;

int a, b, p;

int fast_pow(int a, int b, int p) {
    long res = 1 % p, t = a;
    while (b) {
        if (b & 1) res = res * t % p;
        b >>= 1;

        t = t * t % p;
    }
    return res;
}

int main() {
    scanf("%d%d%d", &a, &b, &p);
    printf("%d^%d mod %d=%d\n", a, b, p, fast_pow(a, b, p));
    return 0;
}