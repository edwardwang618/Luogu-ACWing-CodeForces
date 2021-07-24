#include <iostream>
#include <cstring>
using namespace std;

long qadd(long a, long b, long p) {
    long res = 0;
    while (b) {
        if (b & 1) res = (res + a) % p;
        a = (a + a) % p;
        b >>= 1;
    }

    return res;
}

int main() {
    long a, b, p;
    scanf("%ld%ld%ld", &a, &b, &p);
    printf("%ld\n", qadd(a, b, p));

    return 0;
}