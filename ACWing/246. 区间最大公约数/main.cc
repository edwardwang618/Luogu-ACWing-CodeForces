#include <iostream>
using namespace std;

const int N = 500010;
int n, m;
long a[N];
struct Node {
    int l, r;
    long sum, d;
} tr[4 * N];

long gcd(long a, long b) {
    return !b ? a : gcd(b, a % b);
}

void pushup(Node &u, Node &l, Node &r) {
    u.sum = l.sum + r.sum;
    u.d = gcd(l.d, r.d);
}

void pushup(int u) {
    pushup(tr[u], tr[u << 1], tr[u << 1 | 1]);
}

void build(int u, int l, int r) {
    if (l == r) {
        long b = a[r] - a[r - 1];
        tr[u] = {l, r, b, b};
    } else {
        tr[u] = {l, r};
        int m = l + (r - l >> 1);
        build(u << 1, l, m), build(u << 1 | 1, m + 1, r);
        pushup(u);
    }
}

void modify(int u, int x, long v) {
    if (tr[u].l == x && tr[u].r == x) {
        long b = tr[u].sum + v;
        tr[u] = {x, x, b, b};
    } else {
        int m = tr[u].l + (tr[u].r - tr[u].l >> 1);
        if (x <= m) modify(u << 1, x, v);
        else modify(u << 1 | 1, x, v);

        pushup(u);
    }
}

Node query(int u, int l, int r) {
    if (l > r) return {0};
    if (l <= tr[u].l && tr[u].r <= r) return tr[u];
    else {
        int m = tr[u].l + (tr[u].r - tr[u].l >> 1);
        if (r <= m) return query(u << 1, l, r);
        else if (l > m) return query(u << 1 | 1, l, r);
        else {
            auto left = query(u << 1, l, r), right = query(u << 1 | 1, l, r);
            Node res;
            pushup(res, left, right);
            return res;
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%ld", &a[i]);

    build(1, 1, n);

    int l, r;
    long d;
    char op[2];
    while (m--) {
        scanf("%s%d%d", op, &l, &r);
        if (op[0] == 'Q') {
            auto left = query(1, 1, l), right = query(1, l + 1, r);
            cout << abs(gcd(left.sum, right.d)) << endl;
        } else {
            scanf("%ld", &d);
            modify(1, l, d);
            if (r + 1 <= n) modify(1, r + 1, -d);
        }
    }

    return 0;
}