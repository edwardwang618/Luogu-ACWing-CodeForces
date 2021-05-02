#include <iostream>
using namespace std;

int b, p, k;

int fast_pow(int b, int p, int k) {
    long res = 1, t = b;
    while (p) {
        if (p & 1) res = res * t % k;
        p >>= 1;

        t = t * t % k;
    }
    
    return (int) res % k;
}

int main() {
    scanf("%d%d%d", &b, &p, &k);

    printf("%d^%d mod %d=%d\n", b, p, k, fast_pow(b, p, k));
    return 0;
}