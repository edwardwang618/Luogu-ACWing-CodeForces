#include <iostream>
#include <cstring>
using namespace std;

const int N = 1e5 + 10;
int n, m, p;
int w[N];
struct Node {
    int l, r;
    long sum, add, mul;
} tr[N << 2];

void pushup(int u) {
    tr[u].sum = (tr[u << 1].sum + tr[u << 1 | 1].sum) % p;
}

void calc(Node &u, int add, int mul) {
    u.sum = ((long) u.sum * mul + (long) (u.r - u.l + 1) * add) % p;
    u.mul = (long) u.mul * mul % p;
    u.add = ((long) u.add * mul + add) % p;
}

void pushdown(int u) {
    calc(tr[u << 1], tr[u].add, tr[u].mul);
    calc(tr[u << 1 | 1], tr[u].add, tr[u].mul);
    tr[u].add = 0, tr[u].mul = 1;
}

void build(int u, int l, int r) {
    if (l == r) tr[u] = {l, r, w[l], 0, 1};
    else {
        tr[u] = {l, r, 0, 0, 1};
        int mid = l + r >> 1;
        build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }
}

void modify(int u, int l, int r, int add, int mul) {
    if (l <= tr[u].l && tr[u].r <= r) {
        calc(tr[u], add, mul);
        return;
    }

    pushdown(u);
    int mid = tr[u].l + tr[u].r >> 1;
    if (l <= mid) modify(u << 1, l, r, add, mul);
    if (r > mid) modify(u << 1 | 1, l, r, add, mul);
    pushup(u);
}

int query(int u, int l, int r) {
    if (l <= tr[u].l && tr[u].r <= r) return tr[u].sum;
    
    pushdown(u);
    int res = 0;
    int mid = tr[u].l + tr[u].r >> 1;
    if (l <= mid) res += query(u << 1, l, r);
    if (r > mid) res = (res + query(u << 1 | 1, l, r)) % p;
    return res;
}

int main() {
    scanf("%d%d", &n, &p);
    for (int i = 1; i <= n; i++) scanf("%d", &w[i]);

    build(1, 1, n);

    scanf("%d", &m);
    while (m--) {
        int op, l, r, c;
        scanf("%d%d%d", &op, &l, &r);
        if (op != 3) scanf("%d", &c);
        if (op == 1) modify(1, l, r, 0, c);
        else if (op == 2) modify(1, l, r, c, 1);
        else printf("%d\n", query(1, l, r));
    }
    
    return 0;
}