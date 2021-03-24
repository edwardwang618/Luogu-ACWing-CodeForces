#include <iostream>
using namespace std;

const int N = 200010;
int m, p;
struct Node {
    int l, r;
    int v;
} tr[4 * N];

void pushup(int u) {
    tr[u].v = max(tr[u << 1].v, tr[u << 1 | 1].v);
}

void build(int u, int l, int r) {
    tr[u] = {l, r};
    if (l == r) return;
    int m = l + (r - l >> 1);
    build(u << 1, l, m), build(u << 1 | 1, m + 1, r);
}

int query(int u, int l, int r) {
    if (l <= tr[u].l && tr[u].r <= r) return tr[u].v;

    int m = tr[u].l + (tr[u].r - tr[u].l >> 1);
    int x = 0, y = 0;
    if (l <= m) x = query(u << 1, l, r);
    if (r > m) y = query(u << 1 | 1, l, r);

    return max(x, y);
}

void modify(int u, int x, int v) {
    if (tr[u].l == x && tr[u].r == x) tr[u].v = v;
    else {
        int m = tr[u].l + (tr[u].r - tr[u].l >> 1);
        if (x <= m) modify(u << 1, x, v);
        else modify(u << 1 | 1, x, v);

        pushup(u);
    }
}

int main() {
    int n = 0, last = 0;
    cin >> m >> p;
    build(1, 1, m);

    int x;
    char op[2];
    while (m--) {
        scanf("%s%d", op, &x);
        if (op[0] == 'Q') {
            last = query(1, n - x  + 1, n);
            printf("%d\n", last);
        } else {
            modify(1, n + 1, (last + x) % p);
            n++;
        }
    }
    

    return 0;
}