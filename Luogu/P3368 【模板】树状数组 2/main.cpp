#include <iostream>
#include <cstring>
using namespace std;

const int N = 5e5 + 10;
int n, m;
int tr[N], a[N];

int lowbit(int x) {
    return x & -x;
}

void add(int x, int v) {
    while (x <= n) {
        tr[x] += v;
        x += lowbit(x);
    }
}

int sum(int x) {
    int res = 0;
    while (x) {
        res += tr[x];
        x -= lowbit(x);
    }

    return res;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

    for (int i = 1; i <= n; i++) add(i, a[i] - a[i - 1]);

    while (m--) {
        int type, x, y, k;
        scanf("%d", &type);
        if (type == 1) {
            scanf("%d%d%d", &x, &y, &k);
            add(x, k), add(y + 1, -k);
        } else {
            scanf("%d", &x);
            printf("%d\n", sum(x));
        }
    }

    return 0;
}