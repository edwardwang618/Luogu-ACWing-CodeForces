#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int n, m, tr[N];

int lowbit(int x) {
    return x & -x;
}

void add(int k, int x) {
    for (int i = k; i <= n; i += lowbit(i)) tr[i] += x;
}

int sum(int k) {
    int res = 0;
    for (int i = k; i; i -= lowbit(i)) res += tr[i];
    return res;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        add(i, x);
        add(i + 1, -x);
    }

    while (m--) {
        char op[2];
        scanf("%s", op);

        int x;
        if (*op == 'Q') {
            scanf("%d", &x);
            printf("%d\n", sum(x));
        } else {
            int l, r;
            scanf("%d%d%d", &l, &r, &x);
            add(l, x);
            if (r + 1 <= n) add(r + 1, -x);
        }
    }

    return 0;
}