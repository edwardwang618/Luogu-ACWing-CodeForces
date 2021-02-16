#include <iostream>
using namespace std;

int fast_pow(int a, int k, int p) {
    long res = 1;
    while (k) {
        if (k & 1) res = res * a % p;
        
        k >>= 1;
        a = (long) a * a % p;
    }

    return (int) res;
}

int main() {
    int n;
    cin >> n;

    while (n--) {
        int a, k, p;
        scanf("%d%d%d", &a, &k, &p);

        printf("%d\n", fast_pow(a, k, p));
    }

    return 0;
}