#include <iostream>
#include <cstring>
using namespace std;

const int N = 5e5 + 10;
int n, m;
int tr[N];

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
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        add(i, x);
    }

    while (m--) {
        int type, x, y;
        scanf("%d%d%d", &type, &x, &y);
        if (type == 1) {
            add(x, y);
        } else {
            printf("%d\n", sum(y) - sum(x - 1));
        }
    }

    return 0;
}