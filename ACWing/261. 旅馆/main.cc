#include <iostream>
using namespace std;

const int N = 5e4 + 10;
struct Node{
    int l, r;
    int d, ld, rd;
    int lazy;
} tr[N << 2];
int n, m;

void pushup(Node &u, Node &l, Node &r) {
    u.ld = l.ld;
    if(l.d == l.r - l.l + 1) u.ld = l.d + r.ld;
    u.rd = r.rd;
    if(r.d == r.r - r.l + 1) u.rd = r.d + l.rd;
    u.d = max(max(l.d, r.d), l.rd + r.ld);
}

void pushup(int u) {
    pushup(tr[u], tr[u << 1], tr[u << 1 | 1]);
}

void build(int u, int l, int r) {
    tr[u] = {l, r};
    if (l == r) {
        tr[u].d = tr[u].ld = tr[u].rd = 1;
        return;
    }

    int mid = l + r >> 1;
    build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
    pushup(u);
}

void pushdown(Node &u, Node &l, Node &r) {
    if (u.lazy == 1) {
        l.d = l.ld = l.rd = l.r - l.l + 1;
        r.d = r.ld = r.rd = r.r - r.l + 1;
    } else if(u.lazy == 2) {
        l.d = l.ld = l.rd = r.d = r.ld = r.rd = 0;
    }

    l.lazy = r.lazy = u.lazy;
    u.lazy = 0;
}

void pushdown(int u) {
    if (tr[u].lazy) pushdown(tr[u], tr[u << 1], tr[u << 1 | 1]);
}

int query(int u, int len) {
    if (tr[u].d < len) return 0;

    pushdown(u);
    int mid = tr[u].l + tr[u].r >> 1;
    if (tr[u << 1].d >= len) return query(u << 1, len);
    if (tr[u << 1].rd + tr[u << 1 | 1].ld >= len) return tr[u << 1].r - tr[u << 1].rd + 1;
    if (tr[u << 1 | 1].d >= len) return query(u << 1 | 1, len);

    return 0;
}

void modify(int u, int l, int r, int c) {
    if (tr[u].l >= l && tr[u].r <= r) {
        if (c == 1) tr[u].d = tr[u].ld = tr[u].rd = tr[u].r - tr[u].l + 1;
        else tr[u].d = tr[u].ld = tr[u].rd = 0;
        
        tr[u].lazy = c;
        return;
    }

    pushdown(u);
    int mid = tr[u].l + tr[u].r >> 1;
    if (l <= mid) modify(u << 1, l, r, c);
    if (r > mid) modify(u << 1 | 1, l, r, c);
    pushup(u);
}

int main() {
    scanf("%d%d", &n, &m);
    build(1, 1, n);

    while (m--) {
        int op;
        scanf("%d", &op);
        if (op == 1) {
            int len;
            scanf("%d", &len);
            int l = query(1, len);
            printf("%d\n", l);
            if (l) modify(1, l, l + len - 1, 2);
        } else {
            int l, len;
            scanf("%d%d", &l, &len);
            modify(1, l, l + len - 1, 1);
        }
    }

    return 0;
}