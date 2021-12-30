#include <iostream>
using namespace std;

const int N = 1e6 + 10;
const long MOD = 998244353;
int n;
int a[N], tr[N];
long res, fact[N];

int lowbit(int x) {
    return x & -x;
}

void add(int k, int x) {
    for (int i = k; i <= n; i += lowbit(i)) tr[i] += x;
}

int sum(int k) {
    int cnt = 0;
    for (int i = k; i; i -= lowbit(i)) cnt += tr[i];
    return cnt;
}

int main() {
    scanf("%d", &n);
    fact[0] = 1;
    for (int i = 1; i < n; i++) fact[i] = fact[i - 1] * i % MOD;
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

    for (int i = n; i; i--) {
        res = (res + fact[n - i] * sum(a[i])) % MOD;
        add(a[i], 1);
    }

    res = (res + 1) % MOD;
    printf("%ld\n", res);

    return 0;
}