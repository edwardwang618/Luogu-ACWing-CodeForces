#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int n, m;
struct Node {
    int l, r;
    int val, id;
    int sz, rnd;
} tr[N];
int idx;
int root[N], p[N];

int get_node(int val, int id) {
    tr[++idx].sz = 1;
    tr[idx].val = val;
    tr[idx].id = id;
    tr[idx].rnd = rand();
    return idx;
}

void pushup(int u) {
    tr[u].sz = tr[tr[u].l].sz + tr[tr[u].r].sz + 1;
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

void split(int u, int val, int &x, int &y) {
    if (!u) x = y = 0;
    else {
        if (tr[u].val <= val) {
            x = u;
            split(tr[u].r, val, tr[u].r, y);
        } else {
            y = u;
            split(tr[u].l, val, x, tr[u].l);
        }

        pushup(u);
    }
}

int get_id(int id, int rank) {
    int u = root[id];
    while (u) {
        if (rank <= tr[tr[u].l].sz) u = tr[u].l;
        else if (rank > tr[tr[u].l].sz + 1) {
            rank -= tr[tr[u].l].sz + 1;
            u = tr[u].r;
        } else return tr[u].id;
    }

    return -1;
}

void insert(int u, int b) {
    int x, y;
    split(root[b], tr[u].val, x, y);
    root[b] = merge(merge(x, u), y);
}

void dfs(int u, int b) {
    if (!u) return;

    dfs(tr[u].l, b);
    dfs(tr[u].r, b);
    insert(u, b);
}

int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        p[i] = root[i] = get_node(x, i);
    }

    while (m--) {
        int x, y;
        scanf("%d%d", &x, &y);
        x = find(x), y = find(y);
        if (x != y) {
            if (tr[root[x]].sz > tr[root[y]].sz) swap(x, y);
            p[x] = y;
            dfs(root[x], y);
        }
    }
    
    scanf("%d", &m);
    while (m--) {
        int x, y;
        char op[2];
        scanf("%s%d%d", op, &x, &y);
        x = find(x);
        if (*op == 'B') {
            y = find(y);
            if (x != y) {
                if (tr[root[x]].sz > tr[root[y]].sz) swap(x, y);
                p[x] = y;
                dfs(root[x], y);
            }
        } else {
            int k = y;
            if (tr[root[x]].sz < k) puts("-1");
            else printf("%d\n", get_id(x, k));
        }
    }

    return 0;
}