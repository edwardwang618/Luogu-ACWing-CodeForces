#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int n, m, w[N];
long tr1[N], tr2[N];

int lowbit(int x) {
    return x & -x;
}

void add(int k, long x, long tr[]) {
    for (int i = k; i <= n; i += lowbit(i)) tr[i] += x;
}

long sum(int k, long tr[]) {
    long res = 0;
    for (int i = k; i; i -= lowbit(i)) res += tr[i];
    return res;
}

long pre_sum(int k) {
    return sum(k, tr1) * k - sum(k, tr2);
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &w[i]);

    for (int i = 1; i <= n; i++) {
        add(i, w[i] - w[i - 1], tr1);
        add(i, (long) (i - 1) * (w[i] - w[i - 1]), tr2);
    }

    while (m--) {
        char op[2];
        int l, r, d;
        scanf("%s%d%d", op, &l, &r);
        if (op[0] == 'C') {
            scanf("%d", &d);
            add(l, d, tr1), add(l, (l - 1) * d, tr2);
            add(r + 1, -d, tr1), add(r + 1, r * (-d), tr2);
        } else printf("%ld\n", pre_sum(r) - pre_sum(l - 1));
    }
    
    return 0;
}