#include <iostream>
using namespace std;

const int N = 2e6 + 10;
int n, m;
struct Node {
    int l, r;
    int v, rnd;
    int sz, cnt;
} tr[N];
int root, idx;
int x, y, z;
int res, last;

int get_node(int v) {
    tr[++idx].v = v;
    tr[idx].l = tr[idx].r = 0;
    tr[idx].sz = tr[idx].cnt = 1;
    tr[idx].rnd = rand();
    return idx;
}

void pushup(int u) {
    tr[u].sz = tr[tr[u].l].sz + tr[tr[u].r].sz + tr[u].cnt;
}

void split_key(int u, int key, int &x, int &y) {
    if (!u) x = y = 0;
    else {
        if (tr[u].v <= key) {
            x = u;
            split_key(tr[u].r, key, tr[u].r, y);
            pushup(x);
        } else {
            y = u;
            split_key(tr[u].l, key, x, tr[u].l);
            pushup(y);
        }
    }
}

void split_sz(int u, int sz, int &x, int &y) {
    if (!u) x = y = 0;
    else {
        if (sz > tr[tr[u].l].sz) {
            x = u;
            split_sz(tr[u].r, sz - tr[tr[u].l].sz - tr[u].cnt, tr[u].r, y);
            pushup(x);
        } else {
            y = u;
            split_sz(tr[u].l, sz, x, tr[u].l);
            pushup(y);
        }
    }
}

int merge(int x, int y) {
    if (!x || !y) return x | y;
    if (tr[x].rnd > tr[y].rnd) {
        tr[x].r = merge(tr[x].r, y);
        pushup(x);
        return x;
    } else {
        tr[y].l = merge(x, tr[y].l);
        pushup(y);
        return y;
    }
}

int merge(int x, int y, int z) {
    return merge(merge(x, y), z);
}

void insert(int c) {
    split_key(root, c, y, z);
    split_key(y, c - 1, x, y);
    if (!y) y = get_node(c);
    else {
        tr[y].cnt++;
        tr[y].sz++;
    }

    root = merge(x, y, z);
}

void remove(int c) {
    split_key(root, c, y, z);
    split_key(y, c - 1, x, y);
    tr[y].cnt--;
    tr[y].sz--;
    if (!tr[y].cnt) y = 0;
    root = merge(x, y, z);
}

int get_rank_by_key(int c) {
    split_key(root, c - 1, x, y);
    int rk = tr[x].sz + 1;
    root = merge(x, y);
    return rk;
}

int get_key_by_rank(int rk) {
    split_sz(root, rk, x, y);
    int u = x, key;
    while (u) key = tr[u].v, u = tr[u].r;
    root = merge(x, y);
    return key;
}

int get_prev(int c) {
    split_key(root, c - 1, x, y);
    int u = x, key;
    while (u) key = tr[u].v, u = tr[u].r;
    root = merge(x, y);
    return key;
}

int get_next(int c) {
    split_key(root, c, x, y);
    int u = y, key;
    while (u) key = tr[u].v, u = tr[u].l;
    root = merge(x, y);
    return key;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        int c;
        scanf("%d", &c);
        insert(c);
    }

    while (m--) {
        int op, c;
        scanf("%d%d", &op, &c);
        c ^= last;

        if (op == 1) insert(c);
        else if (op == 2) remove(c);
        else {
            int w;
            if (op == 3) w = get_rank_by_key(c);
            else if (op == 4) w = get_key_by_rank(c);
            else if (op == 5) w = get_prev(c);
            else w = get_next(c);

            res ^= w;
            last = w;
        }
    }

    printf("%d\n", res);

    return 0;
}