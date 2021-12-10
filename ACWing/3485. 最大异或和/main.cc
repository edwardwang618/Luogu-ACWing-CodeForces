#include <iostream>
using namespace std;

const int N = 30e5 + 10;
int n, m;
int a[N];
int son[N][2], cnt[N];
int idx;

void insert(int x, int add) {
    int p = 0;
    for (int i = 30; i >= 0; i--) {
        int c = x >> i & 1;
        if (!son[p][c]) son[p][c] = ++idx;
        p = son[p][c];
        cnt[p] += add;
    }
}

int query(int x) {
    int p = 0, res = 0;
    for (int i = 30; i >= 0; i--) {
        int c = x >> i & 1;
        if (cnt[son[p][!c]]) {
            p = son[p][!c];
            res |= 1 << i;
        } else p = son[p][c];
    }

    return res;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        a[i] ^= a[i - 1];
    }

    int res = 0;
    insert(0, 1);
    for (int i = 1; i <= n; i++) {
        if (i - m - 1 >= 0) insert(a[i - m - 1], -1);
        res = max(res, query(a[i]));
        insert(a[i], 1);
    }

    printf("%d\n", res);

    return 0;
}