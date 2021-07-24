#include <iostream>
#include <cstring>
using namespace std;

const int MOD = 9901;

int qmi(int a, int k) {
    a %= MOD;
    int res = 1;
    while (k) {
        if (k & 1) res = res * a % MOD;
        a = a * a % MOD;
        k >>= 1;
    }
    
    return res;
}

int sum(int p, int k) {
    if (k == 1) return 1;
    if (k % 2 == 0) return (1 + qmi(p, k >> 1)) * sum(p, k / 2) % MOD;
    return (sum(p, k - 1) + qmi(p, k - 1)) % MOD;
}

int main() {
    int a, b;
    scanf("%d%d", &a, &b);

    int res = 1;
    for (int i = 2; i <= a / i; i++)
        if (a % i == 0) {
            int cnt = 0;
            while (a % i == 0) {
                cnt++;
                a /= i;
            }
            
            res = res * sum(i, b * cnt + 1) % MOD;
        }

    if (a > 1) res = res * sum(a, b + 1) % MOD;
    if (a == 0) res = 0;

    printf("%d\n", res);

    return 0;
}