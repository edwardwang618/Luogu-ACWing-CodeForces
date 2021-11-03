#include <iostream>

using namespace std;

const int N = 1e5 + 10;
struct Node {
    int l, r;
    int key, val;
    int size;
    bool reverse;
} tr[N];

int n, m;
int root, idx;

int get_node(int key) {
    tr[++idx].key = key;
    tr[idx].val = rand();
    tr[idx].size = 1;
    return idx;
}

void pushup(int p) {
    tr[p].size = tr[tr[p].l].size + tr[tr[p].r].size + 1;
}

void pushdown(int p) {
    swap(tr[p].l, tr[p].r);
    tr[tr[p].l].reverse ^= 1;
    tr[tr[p].r].reverse ^= 1;
    tr[p].reverse = false;
}

void split(int p, int sz, int &x, int &y) {
    if (!p) x = y = 0;
    else {
        if (tr[p].reverse) pushdown(p);
        if (tr[tr[p].l].size < sz) {
            x = p;
            split(tr[p].r, sz - tr[tr[p].l].size - 1, tr[p].r, y);
        } else {
            y = p;
            split(tr[p].l, sz, x, tr[p].l);
        }

        pushup(p);
    }

}

int merge(int x, int y) {
    if (!x || !y) return x ^ y;
    if (tr[x].val < tr[y].val) {
        if (tr[x].reverse) pushdown(x);
        tr[x].r = merge(tr[x].r, y);
        pushup(x);
        return x;
    } else {
        if (tr[y].reverse) pushdown(y);
        tr[y].l = merge(x, tr[y].l);
        pushup(y);
        return y;
    }
}

void reverse(int l, int r) {
    int x, y, z;
    split(root, l - 1, x, y);
    split(y, r - l + 1, y, z);
    tr[y].reverse ^= 1;
    root = merge(merge(x, y), z);
}

void dfs(int p) {
    if (!p) return;
    if (tr[p].reverse) pushdown(p);
    dfs(tr[p].l);
    printf("%d ", tr[p].key);
    dfs(tr[p].r);
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        root = merge(root, get_node(i));

    while (m--) {
        int l, r;
        scanf("%d%d", &l, &r);
        reverse(l, r);
    }

    dfs(root);

    return 0;
}