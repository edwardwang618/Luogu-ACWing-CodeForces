#include <iostream>
#include <cstring>
using namespace std;

const int N = 2e5 + 10;
int n, a[N];
int tr[N];
int larger[N], smaller[N];

int lowbit(int x) {
    return x & -x;
}

void add(int k, int c) {
    for (int i = k; i <= n; i += lowbit(i)) tr[i] += c;
}

int sum(int k) {
    int res = 0;
    for (int i = k; i; i -= lowbit(i)) res += tr[i];
    return res;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

    for (int i = 1; i <= n; i++) {
        int k = a[i];
        larger[i] = sum(n) - sum(k);
        smaller[i] = sum(k - 1);
        add(k, 1);
    }

    memset(tr, 0, sizeof tr);
    long res1 = 0, res2 = 0;
    for (int i = n; i; i--) {
        int k = a[i];
        res1 += larger[i] * (long) (sum(n) - sum(k));
        res2 += smaller[i] * (long) (sum(k - 1));
        add(k, 1);
    }

    printf("%ld %ld\n", res1, res2);

    return 0;
}