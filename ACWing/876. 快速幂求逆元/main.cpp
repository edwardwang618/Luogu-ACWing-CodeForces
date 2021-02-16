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
        int a, p;
        scanf("%d%d", &a, &p);
        
        int res = fast_pow(a, p - 2, p);
        if (a % p != 0) printf("%d\n", res);
        else printf("impossible\n");
    }

    return 0;
}