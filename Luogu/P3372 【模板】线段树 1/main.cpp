#include <iostream>
#include <cstring>
using namespace std;

const int N = 1e5 + 10;
int n, m;
int w[N];

struct Node {
    int l, r;
    long sum, add;
} tr[4 * N];

void pushup(int u) {
    tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
}

void pushdown(int u) {
    auto &root = tr[u], &left = tr[u << 1], &right = tr[u << 1 | 1];
    if (root.add) {
        left.add += root.add, left.sum += root.add * (left.r - left.l + 1);
        right.add += root.add, right.sum += root.add * (right.r - right.l + 1);
        root.add = 0;
    }
}

void build(int u, int l, int r) {
    if (l == r) tr[u] = {l, l, w[l], 0};
    else {
        tr[u] = {l, r};
        int mid = l + (r - l >> 1);
        build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }
}

void modify(int u, int l, int r, long k) {
    if (tr[u].l >= l && tr[u].r <= r) tr[u].add += k, tr[u].sum += k * (tr[u].r - tr[u].l + 1);
    else {
        pushdown(u);
        int mid = tr[u].l + (tr[u].r - tr[u].l >> 1);
        if (l <= mid) modify(u << 1, l, r, k);
        if (r > mid) modify(u << 1 | 1, l, r, k);
        pushup(u);
    }
}

long query(int u, int l, int r) {
    if (tr[u].l >= l && tr[u].r <= r) return tr[u].sum;
    else {
        pushdown(u);
        int mid = tr[u].l + (tr[u].r - tr[u].l >> 1);
        long sum = 0;
        if (l <= mid) sum += query(u << 1, l, r);
        if (r > mid) sum += query(u << 1 | 1, l, r);
        return sum;
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &w[i]);
    build(1, 1, n);
    while (m--) {
        int t;
        cin >> t;
        int l, r;
        long k;
        if (t == 1) {
            cin >> l >> r >> k;
            modify(1, l, r, k);
        } else {
            cin >> l >> r;
            cout << query(1, l, r) << endl;
        }
    }

    return 0;
}