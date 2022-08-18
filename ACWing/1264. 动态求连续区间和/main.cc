#include <iostream>
#include <cstring>
using namespace std;

const int N = 100010;
int n, m;
int w[N];

struct Node {
    int l, r, sum;
} tr[4 * N];

void push_up(int u) {
    tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
}

void modify(int u, int x, int v) {
    if (tr[u].l == tr[u].r) tr[u].sum += v;
    else {
        int mid = tr[u].l + (tr[u].r - tr[u].l >> 1);
        if (x <= mid) modify(u << 1, x, v);
        else modify(u << 1 | 1, x, v);

        push_up(u);
    }
}

void build(int u, int l, int r) {
    if (l == r) tr[u] = {l, r, w[l]};
    else {
        tr[u] = {l, r};
        int mid = l + (r - l >> 1);
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
        push_up(u);
    }
}

int query(int u, int l, int r) {
    if (l <= tr[u].l && tr[u].r <= r) return tr[u].sum;
    else {
        int mid = tr[u].l + (tr[u].r - tr[u].l >> 1);
        int sum = 0;
        if (mid >= l) sum += query(u << 1, l, r);
        if (r >= mid + 1) sum += query(u << 1 | 1, l, r);
        return sum;
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &w[i]);
    build(1, 1, n);

    while (m--) {
        int k, a, b;
        scanf("%d%d%d", &k, &a, &b);
        if (!k) printf("%d\n", query(1, a, b));
        else modify(1, a, b);
    }

    return 0;
}